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
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

Scanner::Scanner(string file) : fFile(file) {
	this->fInput = new ifstream(this->fFile.c_str(), ifstream::in);

	this->fInput->seekg(0, ios::end);
	this->fLastPos = this->fInput->tellg();
	this->fInput->seekg(0, ios::beg);
}

Scanner::~Scanner() {
	this->fInput->close();
}

Token* Scanner::nextToken() {
	//The last time we retrieved a token, we stopped
	//at the last char in the stream (we have seen
	//the complete input)
	if(fInput->tellg() == this->fLastPos) {
		//always return EOF
		return TokenFactory::getEOF();
	}

	streampos startPos = fInput->tellg();
	State current = this->getStartState();
	streampos lastFinalPos = -1;
	State lastFinal = Scanner::ERR;
	Token* foundToken = NULL;

	static unsigned int lineCounter=0;
    static std::vector<streampos> newlineStack;

	while(foundToken == NULL) {
		int c = fInput->get(); //read next input char

		if(c == -1) {
			//clear eof bit, so that tellg() works on the
			//next call of nextToken
			fInput->clear();
			//if the last state is not final, there is some "open" input
			//in the file, which will never be accepted
			if(!isFinal(current)) {
				throw "premature end of file";
			}
			current = Scanner::ERR; //if we hit EOF, we know that the automaton can't handle it
		} else {
			current = transition(current, c);
		}

		if(current == Scanner::ERR) {
			if(lastFinal == Scanner::ERR) {
				throw "unknown symbol in input";
			}

			char* text = extractText(fInput, startPos, lastFinalPos);
			foundToken = makeToken(lastFinal, text, lineCounter);
			//restore last final pos position in stream, scanning
			//starts from here when nextToken is called again
			fInput->seekg(lastFinalPos);
		}
		if(isFinal(current)) {
			lastFinal = current;
			lastFinalPos = fInput->tellg();
		}

//		if(c=='\n') {
//			lineCounter++;
//			while(newlineStack.size()>0){
//				if(newlineStack.back() < ((int) startPos)-1)
//				{
//					lineCounter--;
//					newlineStack.pop_back();
//				} else {
//					lineCounter++;
//					break;
//				}
//			}
//			newlineStack.push_back(startPos);
//		}
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

//Token* Scanner::handleEOF(Scanner::State lastFinalState, streampos startPos, streampos lastFinal, unsigned int lineCounter) {
//	fEOF = true;
//	ifstream stream(this->fFile.c_str(), ifstream::in);
//	streamsize length;
//	stream.seekg (0, ios::end);
//	length = stream.tellg();
//
//	if(startPos == length) { //last time nextToken was called we were at the end of the file
//		return TokenFactory::getEOF(); //we are now at eof
//	} else if(lastFinal == length) { //we reached a final state with the last char in input
//		char* text = extractText(&stream, startPos, lastFinal);
//		return makeToken(lastFinalState, text, lineCounter); //return appropriate token
// 	} else { //there was input in the file, but we did not reach a final state
// 		throw "Scanner error: premature end of file"; //this is an error
// 	}
//}

Token* Scanner::makeToken(Scanner::State state, char* text, unsigned int line) {
	assert(isFinal(state));

	switch(state){
	case Scanner::p20: return TokenFactory::getGt();
	case Scanner::p30: return TokenFactory::getGe();
	case Scanner::p19: return TokenFactory::getNumber(atoi(text));
	case Scanner::p10: return TokenFactory::getPlus();
	case Scanner::p2: return TokenFactory::getWhitespace();
	case Scanner::p24: return TokenFactory::getRSqParen();
	case Scanner::p14: return TokenFactory::getPoint();
	case Scanner::p22: return TokenFactory::getLt();
	case Scanner::p32: return TokenFactory::getLe();
	case Scanner::p1: return TokenFactory::getIdent(text);
	case Scanner::p7: return TokenFactory::getMod();
	case Scanner::p11: return TokenFactory::getTimes();
	case Scanner::p23: return TokenFactory::getSemicolon();
	case Scanner::p15: return TokenFactory::getDiv();
	case Scanner::p35: return TokenFactory::getComment();
	case Scanner::p25: return TokenFactory::getLSqParen();
	case Scanner::p9: return TokenFactory::getNot();
	case Scanner::p28: return TokenFactory::getNe();
	case Scanner::p12: return TokenFactory::getRParen();
	case Scanner::p16: return TokenFactory::getLParen();
	case Scanner::p21: return TokenFactory::getAssig();
	case Scanner::p31: return TokenFactory::getEq();
	case Scanner::p3: return TokenFactory::getLCurlyParen();
	case Scanner::p5: return TokenFactory::getRCurlyParen();
	case Scanner::p18: return TokenFactory::getComma();
	case Scanner::p13: return TokenFactory::getMinus();
	case Scanner::p17: return TokenFactory::getNumber(0);
	case Scanner::p27: return TokenFactory::getAnd();
	case Scanner::p26: return TokenFactory::getOr();
	default: return TokenFactory::getError();
	};
	return TokenFactory::getError();
}

Scanner::State Scanner::transition(Scanner::State current, char c) {
	switch (current) {
		case p10:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p11:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p30:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p31:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p32:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p33:	switch (c) {
					case '/':	return Scanner::p35;
					case '*':	return Scanner::p33;
					default:	return Scanner::p29;
				}; break;
		case p35:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p17:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p34:	switch (c) {
					case '*':	return Scanner::p36;
					default:	return Scanner::p29;
				}; break;
		case p16:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p19:	switch (c) {
					case '0':	return Scanner::p19;
					case '1':	return Scanner::p19;
					case '5':	return Scanner::p19;
					case '4':	return Scanner::p19;
					case '3':	return Scanner::p19;
					case '2':	return Scanner::p19;
					case '9':	return Scanner::p19;
					case '8':	return Scanner::p19;
					case '7':	return Scanner::p19;
					case '6':	return Scanner::p19;
					default:	return Scanner::ERR;
				}; break;
		case p36:	switch (c) {
					case '/':	return Scanner::p35;
					case '*':	return Scanner::p33;
					default:	return Scanner::p29;
				}; break;
		case p18:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p12:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p15:	switch (c) {
					case '*':	return Scanner::p29;
					default:	return Scanner::ERR;
				}; break;
		case p14:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p0:	switch (c) {
					case 'L':	return Scanner::p1;
					case 'K':	return Scanner::p1;
					case 'J':	return Scanner::p1;
					case 'I':	return Scanner::p1;
					case 'P':	return Scanner::p1;
					case 'O':	return Scanner::p1;
					case 'N':	return Scanner::p1;
					case 'M':	return Scanner::p1;
					case 'D':	return Scanner::p1;
					case 'C':	return Scanner::p1;
					case 'B':	return Scanner::p1;
					case 'A':	return Scanner::p1;
					case 'H':	return Scanner::p1;
					case 'G':	return Scanner::p1;
					case 'F':	return Scanner::p1;
					case 'E':	return Scanner::p1;
					case 'Y':	return Scanner::p1;
					case 'Z':	return Scanner::p1;
					case 'S':	return Scanner::p1;
					case 'T':	return Scanner::p1;
					case 'Q':	return Scanner::p1;
					case 'R':	return Scanner::p1;
					case 'W':	return Scanner::p1;
					case 'X':	return Scanner::p1;
					case 'U':	return Scanner::p1;
					case 'V':	return Scanner::p1;
					case 'n':	return Scanner::p1;
					case 'm':	return Scanner::p1;
					case 'p':	return Scanner::p1;
					case 'o':	return Scanner::p1;
					case 'j':	return Scanner::p1;
					case 'i':	return Scanner::p1;
					case 'l':	return Scanner::p1;
					case 'k':	return Scanner::p1;
					case 'f':	return Scanner::p1;
					case 'e':	return Scanner::p1;
					case 'h':	return Scanner::p1;
					case 'g':	return Scanner::p1;
					case 'b':	return Scanner::p1;
					case 'a':	return Scanner::p1;
					case 'd':	return Scanner::p1;
					case 'c':	return Scanner::p1;
					case 'y':	return Scanner::p1;
					case 'z':	return Scanner::p1;
					case 'u':	return Scanner::p1;
					case 'v':	return Scanner::p1;
					case 'w':	return Scanner::p1;
					case 'x':	return Scanner::p1;
					case 'q':	return Scanner::p1;
					case 'r':	return Scanner::p1;
					case 's':	return Scanner::p1;
					case 't':	return Scanner::p1;
					case ';':	return Scanner::p23;
					case '&':	return Scanner::p8;
					case '!':	return Scanner::p9;
					case '=':	return Scanner::p21;
					case '*':	return Scanner::p11;
					case '5':	return Scanner::p19;
					case '4':	return Scanner::p19;
					case '3':	return Scanner::p19;
					case '2':	return Scanner::p19;
					case '9':	return Scanner::p19;
					case '8':	return Scanner::p19;
					case '7':	return Scanner::p19;
					case '6':	return Scanner::p19;
					case '1':	return Scanner::p19;
					case '%':	return Scanner::p7;
					case '+':	return Scanner::p10;
					case '}':	return Scanner::p5;
					case '-':	return Scanner::p13;
					case ')':	return Scanner::p12;
					case '[':	return Scanner::p25;
					case '.':	return Scanner::p14;
					case '0':	return Scanner::p17;
					case '/':	return Scanner::p15;
					case '|':	return Scanner::p4;
					case '{':	return Scanner::p3;
					case '<':	return Scanner::p22;
					case '>':	return Scanner::p20;
					case ',':	return Scanner::p18;
					case ']':	return Scanner::p24;
					case '(':	return Scanner::p16;
					case '\n':
					case '\t':
					case '\r':
					case ' ':	return Scanner::p2;
					default:	return Scanner::ERR;
				}; break;
		case p5:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p8:	switch (c) {
					case '&':	return Scanner::p27;
					default:	return Scanner::ERR;
				}; break;
		case p7:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p2:	switch (c) {
					case '\n':
					case '\t':
					case '\r':
					case ' ':	return Scanner::p2;
					default:	return Scanner::ERR;
				}; break;
		case p1:	switch (c) {
					case '1':	return Scanner::p1;
					case '0':	return Scanner::p1;
					case 'A':	return Scanner::p1;
					case '4':	return Scanner::p1;
					case '5':	return Scanner::p1;
					case '2':	return Scanner::p1;
					case '3':	return Scanner::p1;
					case '8':	return Scanner::p1;
					case '9':	return Scanner::p1;
					case '6':	return Scanner::p1;
					case '7':	return Scanner::p1;
					case 'q':	return Scanner::p1;
					case 'p':	return Scanner::p1;
					case 'o':	return Scanner::p1;
					case 'n':	return Scanner::p1;
					case 'm':	return Scanner::p1;
					case 'l':	return Scanner::p1;
					case 'k':	return Scanner::p1;
					case 'j':	return Scanner::p1;
					case 'i':	return Scanner::p1;
					case 'h':	return Scanner::p1;
					case 'g':	return Scanner::p1;
					case 'f':	return Scanner::p1;
					case 'e':	return Scanner::p1;
					case 'd':	return Scanner::p1;
					case 'c':	return Scanner::p1;
					case 'b':	return Scanner::p1;
					case 'z':	return Scanner::p1;
					case 'x':	return Scanner::p1;
					case 'y':	return Scanner::p1;
					case 'v':	return Scanner::p1;
					case 'w':	return Scanner::p1;
					case 't':	return Scanner::p1;
					case 'u':	return Scanner::p1;
					case 'r':	return Scanner::p1;
					case 's':	return Scanner::p1;
					case 'O':	return Scanner::p1;
					case 'N':	return Scanner::p1;
					case 'Q':	return Scanner::p1;
					case 'P':	return Scanner::p1;
					case 'K':	return Scanner::p1;
					case 'J':	return Scanner::p1;
					case 'M':	return Scanner::p1;
					case 'L':	return Scanner::p1;
					case 'G':	return Scanner::p1;
					case 'F':	return Scanner::p1;
					case 'I':	return Scanner::p1;
					case 'H':	return Scanner::p1;
					case 'C':	return Scanner::p1;
					case 'B':	return Scanner::p1;
					case 'E':	return Scanner::p1;
					case 'D':	return Scanner::p1;
					case '_':	return Scanner::p1;
					case 'a':	return Scanner::p1;
					case 'Z':	return Scanner::p1;
					case 'V':	return Scanner::p1;
					case 'W':	return Scanner::p1;
					case 'X':	return Scanner::p1;
					case 'Y':	return Scanner::p1;
					case 'R':	return Scanner::p1;
					case 'S':	return Scanner::p1;
					case 'T':	return Scanner::p1;
					case 'U':	return Scanner::p1;
					default:	return Scanner::ERR;
				}; break;
		case p4:	switch (c) {
					case '|':	return Scanner::p26;
					default:	return Scanner::ERR;
				}; break;
		case p3:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p21:	switch (c) {
					case '=':	return Scanner::p31;
					default:	return Scanner::ERR;
				}; break;
		case p9:	switch (c) {
					case '=':	return Scanner::p28;
					default:	return Scanner::ERR;
				}; break;
		case p22:	switch (c) {
					case '=':	return Scanner::p32;
					default:	return Scanner::ERR;
				}; break;
		case p20:	switch (c) {
					case '=':	return Scanner::p30;
					default:	return Scanner::ERR;
				}; break;
		case p26:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p25:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p24:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p23:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p29:	switch (c) {
					case '*':	return Scanner::p33;
					case '/':	return Scanner::p34;
					default:	return Scanner::p29;
				}; break;
		case p28:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p27:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		case p13:	switch (c) {
					default:	return Scanner::ERR;
				}; break;
		default:	return Scanner::ERR;
	};
	return Scanner::ERR;
}

bool Scanner::isFinal(Scanner::State state) {
	return state == p10 || state == p11 || state == p30 ||
		   state == p31 || state == p32 || state == p35 ||
		   state == p17 || state == p16 || state == p19 ||
		   state == p18 || state == p12 || state == p15 ||
		   state == p14 || state == p5 || state == p7 ||
		   state == p2 || state == p1 || state == p3 ||
		   state == p21 || state == p9 || state == p22 ||
		   state == p20 || state == p26 || state == p25 ||
		   state == p24 || state == p23 || state == p28 ||
		   state == p27 || state == p13;
}

Scanner::State Scanner::getStartState() {
	return Scanner::p0;
}
