/*
 * Screener.cpp
 *
 *  Created on: Oct 21, 2011
 *      Author: michaelbohn
 */

#include "Screener.h"

Screener::Screener(Scanner* scanner) : fScanner(scanner) {
}

Screener::~Screener() {
}

Token* Screener::nextToken() {
	Token* token = fScanner->nextToken();
	//TODO filter tokens we don't like (comments, whitespace)
	//TODO convert identifiers that are keywords to keyword tokens
	return token;
}

