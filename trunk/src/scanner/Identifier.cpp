/*
 * Identifier.cpp
 *
 *  Created on: 23.10.2011
 *      Author: barbara
 */

#include "Identifier.h"

Identifier::Identifier(string s): Token(Token::T_IDENT) {
	this->identifier = s;
}

string Identifier::getIdentifier() {
	return this->identifier;
}

Identifier::~Identifier() {
}

