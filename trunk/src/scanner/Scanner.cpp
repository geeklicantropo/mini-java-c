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

	//TEST
	cout << "text=" << text << endl;
	if(state == Scanner::Q1) {
		cout << "keyword a found" << endl;
	} else if(state == Scanner::Q2) {
		cout << "ident aa* found" << endl;
	} else {
		cout << "error";
	}

	//never return NULL, or scanner while loop forever
	//TODO make token for each final state (using the factory)
	return TokenFactory::getLParen(); //just for test
}

Scanner::State Scanner::transition(Scanner::State current, char c) {
	if(current == Scanner::START) {
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
	}
	return Scanner::ERR;
}

bool Scanner::isFinal(Scanner::State state) {
	return state == Scanner::Q1 || state == Scanner::Q2;
}

Scanner::State Scanner::getStartState() {
	return Scanner::START;
}
