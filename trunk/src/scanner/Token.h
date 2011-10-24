/*
 * Token.h
 *
 *  Created on: Oct 21, 2011
 *      Author: michaelbohn
 */

#ifndef TOKEN_H_
#define TOKEN_H_

class Token {
public:
	enum Tag {
		T_EOF,
		T_LPAREN,
		T_RPAREN,
		T_LCURLYPAREN,
		T_RCURLYPAREN,
		T_LSQPAREN,
		T_RSQPAREN,
		T_SEMICOLON,
		T_COMMA,
		T_POINT,
		T_OR,
		T_AND,
		T_NOT,
		T_EQ,
		T_NE,
		T_LT,
		T_LE,
		T_GT,
		T_GE,
		T_ASSIG,
		T_PLUS,
		T_MINUS,
		T_TIMES,
		T_DIV,
		T_MOD,
		T_IDENT,
		T_NUMBER,
		//
		T_STRING,
		T_CLASS,
		T_PUBLIC,
		T_STATIC,
		T_VOID,
		T_MAIN,
		T_INT,
		T_BOOLEAN,
		T_WHILE,
		T_IF,
		T_ELSE,
		T_SYSTEM,
		T_OUT,
		T_PRINTLN,
		T_RETURN,
		T_NULL,
		T_FALSE,
		T_TRUE,
		T_THIS,
		T_NEW,
		//
		T_WHITESPACE,
		T_COMMENT,
		//
		T_ERROR
	};
	Token(Token::Tag);
	Tag getTag();
	virtual ~Token();
private:
	Tag fTag;
};

#endif /* TOKEN_H_ */
