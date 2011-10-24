/*
 * Scanner.cpp
 *
 *  Created on: Oct 21, 2011
 *      Author: michaelbohn
 */

#include "Scanner.h"
#include "TokenFactory.h"

#include <iostream>
#include <assert.h>

using namespace std;

Scanner::Scanner(string file) : fFile(file) {
	this->fInput = new ifstream(this->fFile.c_str(), ifstream::in);
}

Scanner::~Scanner() {
	this->fInput->close();
}

Token* Scanner::nextToken() {
	if(fEOF) { //once we reach EOF once, the nextToken function will always return EOF
		return TokenFactory::getEOF();
	}

	streampos startPos = fInput->tellg();
	State current = this->getStartState();
	streampos lastFinalPos = -1;
	State lastFinal = Scanner::ERR;
	Token* foundToken = NULL;
	while(foundToken == NULL) {
		int c = fInput->get(); //read next input char
		if(c == -1) { //eof reached
			//special handling, since once the stream reaches EOF
			//seekg does not work anymore :(
			foundToken = handleEOF(lastFinal, startPos, lastFinalPos);
		} else {
			current = transition(current, c);
			if(current == Scanner::ERR) {
				if(lastFinal == Scanner::ERR) {
					throw "Scanner error"; //we did not find a final state
				}
				char* text = extractText(fInput, startPos, lastFinalPos);
				foundToken = makeToken(lastFinal, text);
				//restore last final pos position in stream, scanning
				//starts from here when nextToken is called again
				fInput->seekg(lastFinalPos);
			}
			if(isFinal(current)) {
				lastFinal = current;
				lastFinalPos = fInput->tellg();
			}
		}
	}
	//invariant: foundToken != NULL
	return foundToken;
}

char* Scanner::extractText(ifstream* stream, streampos start, streampos end) {
	streamsize length = end - start;
	stream->seekg(start);
	char* text = new char(length+1);
	stream->read(text, length);
	text[length] = '\0';
	return text;
}

Token* Scanner::handleEOF(Scanner::State lastFinalState, streampos startPos, streampos lastFinal) {
	fEOF = true;
	ifstream stream(this->fFile.c_str(), ifstream::in);
	streamsize length;
	stream.seekg (0, ios::end);
	length = stream.tellg();

	if(startPos == length) { //last time nextToken was called we were at the end of the file
		return TokenFactory::getEOF(); //we are now at eof
	} else if(lastFinal == length) { //we reached a final state with the last char in input
		char* text = extractText(&stream, startPos, lastFinal);
		return makeToken(lastFinalState, text); //return appropriate token
 	} else { //there was input in the file, but we did not reach a final state
 		throw "Scanner error: premature end of file"; //this is an error
 	}
}

Token* Scanner::makeToken(Scanner::State state, char* text) {
	assert(isFinal(state));

	if(state == Scanner::p20) {
		return TokenFactory::getGt();
	} else if(state == Scanner::p30) {
		return TokenFactory::getGe();
	} else if(state == Scanner::p19) {
		int i = 0;
		cout << text << endl;
		return TokenFactory::getNumber(sscanf(text, "%d", &i)); // TODO: where to get correct number from?
	} else if(state == Scanner::p10) {
		return TokenFactory::getPlus();
	} else if(state == Scanner::p2) {
		return TokenFactory::getWhitespace();
	} else if(state == Scanner::p24) {
		return TokenFactory::getRSqParen();
	} else if(state == Scanner::p14) {
		return TokenFactory::getPoint();
	} else if(state == Scanner::p22) {
		return TokenFactory::getLt();
	} else if(state == Scanner::p32) {
		return TokenFactory::getLe();
	} else if(state == Scanner::p1) {
		return TokenFactory::getIdent(text); // TODO: where to get correct identifier from?
	} else if(state == Scanner::p7) {
		return TokenFactory::getMod();
	} else if(state == Scanner::p11) {
		return TokenFactory::getTimes();
	} else if(state == Scanner::p23) {
		return TokenFactory::getSemicolon();
	} else if(state == Scanner::p15) {
		return TokenFactory::getDiv();
	} else if(state == Scanner::p35) {
		return TokenFactory::getComment();
	} else if(state == Scanner::p25) {
		return TokenFactory::getLSqParen();
	} else if(state == Scanner::p9) {
		return TokenFactory::getNot();
	} else if(state == Scanner::p28) {
		return TokenFactory::getNe();
	} else if(state == Scanner::p12) {
		return TokenFactory::getRParen();
	} else if(state == Scanner::p16) {
		return TokenFactory::getLParen();
	} else if(state == Scanner::p21) {
		return TokenFactory::getAssig();
	} else if(state == Scanner::p31) {
		return TokenFactory::getEq();
	} else if(state == Scanner::p3) {
		return TokenFactory::getLCurlyParen();
	} else if(state == Scanner::p5) {
		return TokenFactory::getRCurlyParen();
	} else if(state == Scanner::p18) {
		return TokenFactory::getComma();
	} else if(state == Scanner::p13) {
		return TokenFactory::getMinus();
	} else if(state == Scanner::p17) {
		return TokenFactory::getNumber(0);
	} else if(state == Scanner::p27) {
		return TokenFactory::getAnd();
	} else if(state == Scanner::p26) {
		return TokenFactory::getOr();
	} else {
		return TokenFactory::getError();
	}
	//TEST
	/*cout << "text=" << text << endl;
	if(state == Scanner::Q1) {
		cout << "keyword a found" << endl;
	} else if(state == Scanner::Q2) {
		cout << "ident aa* found" << endl;
	} else {
		cout << "error";
	}*/

	//never return NULL, or scanner while loop forever
	//TODO make token for each final state (using the factory)
	//return TokenFactory::getLParen(); //just for test
}

Scanner::State Scanner::transition(Scanner::State current, char c) {
	/*if(current == Scanner::START) {
		if(c == 'a') {
			return Scanner::Q1;
		} else {
			return Scanner::ERR;
		}
	} else if(current == Scanner::Q1) {
		if(c == 'a') {
			return Scanner::Q2;
		} else {
			return Scanner::ERR;
		}
	} else if(current == Scanner::Q2) {
		if(c == 'a') {
			return Scanner::Q2;
		} else {
			return Scanner::ERR;
		}
	}*/
	if(current == Scanner::p10) {
		return Scanner::ERR;
	} else if(current == Scanner::p11) {
		return Scanner::ERR;
	} else if(current == Scanner::p30) {
		return Scanner::ERR;
	} else if(current == Scanner::p31) {
		return Scanner::ERR;
	} else if(current == Scanner::p32) {
		return Scanner::ERR;
	} else if(current == Scanner::p33) {
		if(c == '*') {
			return Scanner::p33;
		} else if(c == '/') {
			return Scanner::p35;
		} else {
			return Scanner::p29;
		}
	} else if(current == Scanner::p35) {
		return Scanner::ERR;
	} else if(current == Scanner::p17) {
		return Scanner::ERR;
	} else if(current == Scanner::p34) {
		if(c == '*') {
			return Scanner::p36;
		} else {
			return Scanner::p29;
		}
	} else if(current == Scanner::p16) {
		return Scanner::ERR;
	} else if(current == Scanner::p19) {
		if(c == '0') {
			return Scanner::p19;
		} else if(c == '1') {
			return Scanner::p19;
		} else if(c == '5') {
			return Scanner::p19;
		} else if(c == '4') {
			return Scanner::p19;
		} else if(c == '3') {
			return Scanner::p19;
		} else if(c == '2') {
			return Scanner::p19;
		} else if(c == '8') {
			return Scanner::p19;
		} else if(c == '7') {
			return Scanner::p19;
		} else if(c == '6') {
			return Scanner::p19;
		} else {
			return Scanner::ERR;
		}
	} else if(current == Scanner::p36) {
		if(c == '*') {
			return Scanner::p33;
		} else if(c == '/') {
			return Scanner::p35;
		} else {
			return Scanner::p29;
		}
	} else if(current == Scanner::p18) {
		return Scanner::ERR;
	} else if(current == Scanner::p13) {
		return Scanner::ERR;
	} else if(current == Scanner::p12) {
		return Scanner::ERR;
	} else if(current == Scanner::p15) {
		if(c == '*') {
			return Scanner::p29;
		} else {
			return Scanner::ERR;
		}
	} else if(current == Scanner::p14) {
		return Scanner::ERR;
	} else if(current == Scanner::p0) {
		if(c == '>') {
			return Scanner::p20;
		} else if(c == '5') {
			return Scanner::p19;
		} else if(c == '4') {
			return Scanner::p19;
		} else if(c == '3') {
			return Scanner::p19;
		} else if(c == '2') {
			return Scanner::p19;
		} else if(c == '9') {
			return Scanner::p19;
		} else if(c == '8') {
			return Scanner::p19;
		} else if(c == '7') {
			return Scanner::p19;
		} else if(c == '6') {
			return Scanner::p19;
		} else if(c == '1') {
			return Scanner::p19;
		} else if(c == '+') {
			return Scanner::p10;
		} else if(c == '%') {
			return Scanner::p7;
		} else if(c == '*') {
			return Scanner::p11;
		} else if(c == '(') {
			return Scanner::p16;
		} else if(c == '{') {
			return Scanner::p3;
		} else if(c == '}') {
			return Scanner::p5;
		} else if(c == '[') {
			return Scanner::p25;
		} else if(c == ',') {
			return Scanner::p18;
		} else if(c == '0') {
			return Scanner::p17;
		} else if(c == '|') {
			return Scanner::p4;
		} else if(c == '\n' || c == '\t' || c == '\r' || c == ' ') {
			return Scanner::p2;
		} else if(c == ']') {
			return Scanner::p24;
		} else if(c == '.') {
			return Scanner::p14;
		} else if(c == 'L') {
			return Scanner::p1;
		} else if(c == 'K') {
			return Scanner::p1;
		} else if(c == 'J') {
			return Scanner::p1;
		} else if(c == 'I') {
			return Scanner::p1;
		} else if(c == 'P') {
			return Scanner::p1;
		} else if(c == 'O') {
			return Scanner::p1;
		} else if(c == 'N') {
			return Scanner::p1;
		} else if(c == 'M') {
			return Scanner::p1;
		} else if(c == 'D') {
			return Scanner::p1;
		} else if(c == 'C') {
			return Scanner::p1;
		} else if(c == 'B') {
			return Scanner::p1;
		} else if(c == 'A') {
			return Scanner::p1;
		} else if(c == 'H') {
			return Scanner::p1;
		} else if(c == 'G') {
			return Scanner::p1;
		} else if(c == 'F') {
			return Scanner::p1;
		} else if(c == 'E') {
			return Scanner::p1;
		} else if(c == 'Y') {
			return Scanner::p1;
		} else if(c == 'Z') {
			return Scanner::p1;
		} else if(c == 'S') {
			return Scanner::p1;
		} else if(c == 'T') {
			return Scanner::p1;
		} else if(c == 'Q') {
			return Scanner::p1;
		} else if(c == 'R') {
			return Scanner::p1;
		} else if(c == 'W') {
			return Scanner::p1;
		} else if(c == 'X') {
			return Scanner::p1;
		} else if(c == 'U') {
			return Scanner::p1;
		} else if(c == 'V') {
			return Scanner::p1;
		} else if(c == 'n') {
			return Scanner::p1;
		} else if(c == 'm') {
			return Scanner::p1;
		} else if(c == 'p') {
			return Scanner::p1;
		} else if(c == 'o') {
			return Scanner::p1;
		} else if(c == 'j') {
			return Scanner::p1;
		} else if(c == 'i') {
			return Scanner::p1;
		} else if(c == 'l') {
			return Scanner::p1;
		} else if(c == 'k') {
			return Scanner::p1;
		} else if(c == 'f') {
			return Scanner::p1;
		} else if(c == 'e') {
			return Scanner::p1;
		} else if(c == 'h') {
			return Scanner::p1;
		} else if(c == 'g') {
			return Scanner::p1;
		} else if(c == 'b') {
			return Scanner::p1;
		} else if(c == 'a') {
			return Scanner::p1;
		} else if(c == 'd') {
			return Scanner::p1;
		} else if(c == 'c') {
			return Scanner::p1;
		} else if(c == 'y') {
			return Scanner::p1;
		} else if(c == 'z') {
			return Scanner::p1;
		} else if(c == 'u') {
			return Scanner::p1;
		} else if(c == 'v') {
			return Scanner::p1;
		} else if(c == 'w') {
			return Scanner::p1;
		} else if(c == 'x') {
			return Scanner::p1;
		} else if(c == 'q') {
			return Scanner::p1;
		} else if(c == 'r') {
			return Scanner::p1;
		} else if(c == 's') {
			return Scanner::p1;
		} else if(c == 't') {
			return Scanner::p1;
		} else if(c == ';') {
			return Scanner::p23;
		} else if(c == '/') {
			return Scanner::p15;
		} else if(c == '&') {
			return Scanner::p8;
		} else if(c == ')') {
			return Scanner::p12;
		} else if(c == '<') {
			return Scanner::p22;
		} else if(c == '!') {
			return Scanner::p9;
		} else if(c == '=') {
			return Scanner::p21;
		} else if(c == '-') {
			return Scanner::p13;
		} else {
			return Scanner::ERR;
		}
	} else if(current == Scanner::p5) {
		return Scanner::ERR;
	} else if(current == Scanner::p8) {
		if(c == '&') {
			return Scanner::p27;
		} else {
			return Scanner::ERR;
		}
	} else if(current == Scanner::p7) {
		return Scanner::ERR;
	} else if(current == Scanner::p2) {
		if(c == '\n' || c == '\t' || c == '\r' || c == ' ') {
			return Scanner::p2;
		} else {
			return Scanner::ERR;
		}
	} else if(current == Scanner::p1) {
		if(c == '1') {
			return Scanner::p1;
		} else if(c == '0') {
			return Scanner::p1;
		} else if(c == 'A') {
			return Scanner::p1;
		} else if(c == '4') {
			return Scanner::p1;
		} else if(c == '5') {
			return Scanner::p1;
		} else if(c == '2') {
			return Scanner::p1;
		} else if(c == '3') {
			return Scanner::p1;
		} else if(c == '8') {
			return Scanner::p1;
		} else if(c == '9') {
			return Scanner::p1;
		} else if(c == '6') {
			return Scanner::p1;
		} else if(c == '7') {
			return Scanner::p1;
		} else if(c == 'q') {
			return Scanner::p1;
		} else if(c == 'p') {
			return Scanner::p1;
		} else if(c == 'o') {
			return Scanner::p1;
		} else if(c == 'n') {
			return Scanner::p1;
		} else if(c == 'm') {
			return Scanner::p1;
		} else if(c == 'l') {
			return Scanner::p1;
		} else if(c == 'k') {
			return Scanner::p1;
		} else if(c == 'j') {
			return Scanner::p1;
		} else if(c == 'i') {
			return Scanner::p1;
		} else if(c == 'h') {
			return Scanner::p1;
		} else if(c == 'g') {
			return Scanner::p1;
		} else if(c == 'f') {
			return Scanner::p1;
		} else if(c == 'e') {
			return Scanner::p1;
		} else if(c == 'd') {
			return Scanner::p1;
		} else if(c == 'c') {
			return Scanner::p1;
		} else if(c == 'b') {
			return Scanner::p1;
		} else if(c == 'z') {
			return Scanner::p1;
		} else if(c == 'x') {
			return Scanner::p1;
		} else if(c == 'y') {
			return Scanner::p1;
		} else if(c == 'v') {
			return Scanner::p1;
		} else if(c == 'w') {
			return Scanner::p1;
		} else if(c == 't') {
			return Scanner::p1;
		} else if(c == 'u') {
			return Scanner::p1;
		} else if(c == 'r') {
			return Scanner::p1;
		} else if(c == 's') {
			return Scanner::p1;
		} else if(c == 'O') {
			return Scanner::p1;
		} else if(c == 'N') {
			return Scanner::p1;
		} else if(c == 'Q') {
			return Scanner::p1;
		} else if(c == 'P') {
			return Scanner::p1;
		} else if(c == 'K') {
			return Scanner::p1;
		} else if(c == 'J') {
			return Scanner::p1;
		} else if(c == 'M') {
			return Scanner::p1;
		} else if(c == 'L') {
			return Scanner::p1;
		} else if(c == 'G') {
			return Scanner::p1;
		} else if(c == 'F') {
			return Scanner::p1;
		} else if(c == 'I') {
			return Scanner::p1;
		} else if(c == 'H') {
			return Scanner::p1;
		} else if(c == 'C') {
			return Scanner::p1;
		} else if(c == 'B') {
			return Scanner::p1;
		} else if(c == 'E') {
			return Scanner::p1;
		} else if(c == 'D') {
			return Scanner::p1;
		} else if(c == '_') {
			return Scanner::p1;
		} else if(c == 'a') {
			return Scanner::p1;
		} else if(c == 'Z') {
			return Scanner::p1;
		} else if(c == 'V') {
			return Scanner::p1;
		} else if(c == 'W') {
			return Scanner::p1;
		} else if(c == 'X') {
			return Scanner::p1;
		} else if(c == 'Y') {
			return Scanner::p1;
		} else if(c == 'R') {
			return Scanner::p1;
		} else if(c == 'S') {
			return Scanner::p1;
		} else if(c == 'T') {
			return Scanner::p1;
		} else if(c == 'U') {
			return Scanner::p1;
		} else {
			return Scanner::ERR;
		}
	} else if(current == Scanner::p4) {
		if(c == '|') {
			return Scanner::p26;
		} else {
			return Scanner::ERR;
		}
	} else if(current == Scanner::p3) {
		return Scanner::ERR;
	} else if(current == Scanner::p21) {
		if(c == '=') {
			return Scanner::p31;
		} else {
			return Scanner::ERR;
		}
	} else if(current == Scanner::p9) {
		if(c == '=') {
			return Scanner::p28;
		} else {
			return Scanner::ERR;
		}
	} else if(current == Scanner::p22) {
		if(c == '=') {
			return Scanner::p32;
		} else {
			return Scanner::ERR;
		}
	} else if(current == Scanner::p20) {
		if(c == '=') {
			return Scanner::p30;
		} else {
			return Scanner::ERR;
		}
	} else if(current == Scanner::p26) {
		return Scanner::ERR;
	} else if(current == Scanner::p25) {
		return Scanner::ERR;
	} else if(current == Scanner::p24) {
		return Scanner::ERR;
	} else if(current == Scanner::p23) {
		return Scanner::ERR;
	} else if(current == Scanner::p29) {
		if(c == '*') {
			return Scanner::p33;
		} else if(c == '/') {
			return Scanner::p34;
		} else {
			return Scanner::p29;
		}
	} else if(current == Scanner::p28) {
		return Scanner::ERR;
	} else if(current == Scanner::p27) {
		return Scanner::ERR;
	}
	return Scanner::ERR;
}

bool Scanner::isFinal(Scanner::State state) {
	return state == p10 || state == p11 || state == p30 || state == p31 || state == p32 || state == p35 || state == p17 || state == p16 || state == p19 || state == p18 || state == p13 || state == p12 || state == p15 || state == p14 || state == p5 || state == p7 || state == p2 || state == p1 || state == p3 || state == p21 || state == p9 || state == p22 || state == p20 || state == p26 || state == p25 || state == p24 || state == p23 || state == p28 || state == p27;
	//return state == Scanner::Q1 || state == Scanner::Q2;
}

Scanner::State Scanner::getStartState() {
	return Scanner::p0;
	//return Scanner::START;
}
