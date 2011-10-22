/*
 * Scanner.cpp
 *
 *  Created on: Oct 21, 2011
 *      Author: michaelbohn
 */

#include "Scanner.h"
#include "TokenFactory.h"

#include <iostream>

using namespace std;

Scanner::Scanner(string file) : fFile(file) {
	this->fInput = new ifstream(this->fFile.c_str(), ifstream::in);
}

Scanner::~Scanner() {
	this->fInput->close();
}

Token* Scanner::nextToken() {
	//TODO remember position in stream where we started (s)
	State current = Scanner::START;
	State lastFinal;
	Token* foundToken = NULL;
	int c;
	while(foundToken == NULL) {
		c = fInput->get();
		//TODO what happens if eof is reached?
		State nextState = transition(current, c);
		if(nextState == Scanner::ERR) {
			//TODO rewind position in stream to last final position (f)
			//TODO extract text from stream in interval [s,f]
			string text = "test";
			foundToken = makeToken(lastFinal, text);
		}
		if(isFinal(nextState)) {
			lastFinal = nextState;
			//TODO remember position in stream
		}
	}
	//invariant: foundToken != NULL
	return foundToken;
}


Token* Scanner::makeToken(Scanner::State state, string text) {
	return NULL;
}

Scanner::State Scanner::transition(Scanner::State current, char c) {
	return Scanner::ERR;
}

bool Scanner::isFinal(Scanner::State state) {
	return true;
}
