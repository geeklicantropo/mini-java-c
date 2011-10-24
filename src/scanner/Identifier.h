/*
 * Identifier.h
 *
 *  Created on: 23.10.2011
 *      Author: barbara
 */

#ifndef IDENTIFIER_H_
#define IDENTIFIER_H_

#include <string>

#include "Token.h"

using namespace std;

class Identifier: public Token {
public:
	Identifier(char* s);
	virtual ~Identifier();
	char* getIdentifier();

private:
	char* identifier;
};

#endif /* IDENTIFIER_H_ */
