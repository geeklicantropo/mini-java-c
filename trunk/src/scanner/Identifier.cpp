/*
 * Identifier.cpp
 *
 *  Created on: 23.10.2011
 *      Author: barbara
 */

#include "Identifier.h"

Identifier::Identifier(char* s): Token(Token::T_IDENT) {
	this->identifier = s;
}

char* Identifier::getIdentifier() {
	return this->identifier;
}

Identifier::~Identifier() {
}


std::ostream& operator<<(std::ostream& aStream, Identifier& aIdent)
{
    return aStream << aIdent.getIdentifier();
}

