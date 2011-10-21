/*
 * TokenFactory.h
 *
 *  Created on: Oct 21, 2011
 *      Author: michaelbohn
 */

#ifndef TOKENFACTORY_H_
#define TOKENFACTORY_H_

#include "Token.h"

class TokenFactory {
public:
	static Token* getEOF();
	static Token* getLParen(); //(
};

#endif /* TOKENFACTORY_H_ */
