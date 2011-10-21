/*
 * Token.cpp
 *
 *  Created on: Oct 21, 2011
 *      Author: michaelbohn
 */

#include "Token.h"

//TODO for each Token with attributes, create a subclass
//     and store attributes
Token::Token(Token::Tag tag) : fTag(tag) {
}

Token::Tag Token::getTag() {
	return fTag;
}

Token::~Token() {
}

