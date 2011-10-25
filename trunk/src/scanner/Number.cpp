/*
 * Number.cpp
 *
 *  Created on: 23.10.2011
 *      Author: barbara
 */

#include "Number.h"

Number::Number(int i): Token(Token::T_NUMBER) {
	this->number = i;
}

Number::~Number() {
}

int Number::getNumber() {
	return this->number;
}

std::ostream& operator<<(std::ostream& aStream, Number& aNumber)
{
    return aStream << aNumber.getNumber();
}


