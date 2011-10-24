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
	static Token* getRParen();
	static Token* getLCurlyParen();
	static Token* getRCurlyParen();
	static Token* getLSqParen();
	static Token* getRSqParen();
	static Token* getSemicolon();
	static Token* getComma();
	static Token* getPoint();
	static Token* getOr();
	static Token* getAnd();
	static Token* getNot();
	static Token* getEq();
	static Token* getNe();
	static Token* getLt();
	static Token* getLe();
	static Token* getGt();
	static Token* getGe();
	static Token* getAssig();
	static Token* getPlus();
	static Token* getMinus();
	static Token* getTimes();
	static Token* getDiv();
	static Token* getMod();
	static Token* getIdent(char* s);
	static Token* getNumber(int i);

	static Token* getString();
	static Token* getClass();
	static Token* getPublic();
	static Token* getStatic();
	static Token* getVoid();
	static Token* getMain();
	static Token* getInt();
	static Token* getBoolean();
	static Token* getWhile();
	static Token* getIf();
	static Token* getElse();
	static Token* getSystem();
	static Token* getOut();
	static Token* getPrintln();
	static Token* getReturn();
	static Token* getNull();
	static Token* getTrue();
	static Token* getFalse();
	static Token* getThis();
	static Token* getNew();

	static Token* getWhitespace();
	static Token* getComment();

	static Token* getError();
};

#endif /* TOKENFACTORY_H_ */
