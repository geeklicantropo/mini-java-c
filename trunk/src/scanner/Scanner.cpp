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
	//TODO open file as character stream
}

Scanner::~Scanner() {
}

Token* Scanner::nextToken() {
	//TODO Test
	static bool flag = true;
	if(flag) {
		flag = false;
		return TokenFactory::getLParen();
	} else {
		return TokenFactory::getEOF();
	}

	//TODO the automaton stuff happens here
}
