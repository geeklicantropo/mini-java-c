/*
 * TokenFactory.cpp
 *
 *  Created on: Oct 21, 2011
 *      Author: michaelbohn
 */

#include "TokenFactory.h"
#include "Token.h"
#include <cstddef>
#include <iostream>

Token* TokenFactory::getEOF() {
	static Token* t_eof = NULL;
	if(t_eof == NULL) {
		t_eof = new Token(Token::T_EOF);
	}
	return t_eof;
}

Token* TokenFactory::getLParen() {
	static Token* t_lparen = NULL;
	if(t_lparen == NULL) {
		t_lparen = new Token(Token::T_LPAREN);
	}
	return t_lparen;
}
