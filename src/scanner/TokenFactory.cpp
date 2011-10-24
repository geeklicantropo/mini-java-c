/*
 * TokenFactory.cpp
 *
 *  Created on: Oct 21, 2011
 *      Author: michaelbohn
 */

#include "TokenFactory.h"
#include "Token.h"
#include "Identifier.h"
#include "Number.h"

#include <cstddef>
#include <iostream>

Token* TokenFactory::getEOF() {
	static Token* t_eof = NULL;
	if(t_eof == NULL) {
		t_eof = new Token(Token::T_EOF);
	}
	cout << "eof" << endl;
	return t_eof;
}

Token* TokenFactory::getLParen() {
	static Token* t_lparen = NULL;
	if(t_lparen == NULL) {
		t_lparen = new Token(Token::T_LPAREN);
	}
	cout << "lparen" << endl;
	return t_lparen;
}

Token* TokenFactory::getRParen() {
	static Token* t_rparen = NULL;
	if(t_rparen == NULL) {
		t_rparen = new Token(Token::T_RPAREN);
	}
	cout << "rparen" << endl;
	return t_rparen;
}

Token* TokenFactory::getLCurlyParen() {
	static Token* t_lcurlyparen = NULL;
	if(t_lcurlyparen == NULL) {
		t_lcurlyparen = new Token(Token::T_LCURLYPAREN);
	}
	cout << "lcurlyparen" << endl;
	return t_lcurlyparen;
}

Token* TokenFactory::getRCurlyParen() {
	static Token* t_rcurlyparen = NULL;
	if(t_rcurlyparen == NULL) {
		t_rcurlyparen = new Token(Token::T_RCURLYPAREN);
	}
	cout << "rcurlyparen" << endl;
	return t_rcurlyparen;
}

Token* TokenFactory::getLSqParen() {
	static Token* t_lsqparen = NULL;
	if(t_lsqparen == NULL) {
		t_lsqparen = new Token(Token::T_LSQPAREN);
	}
	cout << "lsqparen" << endl;
	return t_lsqparen;
}

Token* TokenFactory::getRSqParen() {
	static Token* t_rsqparen = NULL;
	if(t_rsqparen == NULL) {
		t_rsqparen = new Token(Token::T_RSQPAREN);
	}
	cout << "rsqparen" << endl;
	return t_rsqparen;
}

Token* TokenFactory::getSemicolon() {
	static Token* t_semicolon = NULL;
	if(t_semicolon == NULL) {
		t_semicolon = new Token(Token::T_SEMICOLON);
	}
	cout << "semicolon" << endl;
	return t_semicolon;
}

Token* TokenFactory::getComma() {
	static Token* t_comma = NULL;
	if(t_comma == NULL) {
		t_comma = new Token(Token::T_COMMA);
	}
	cout << "comma" << endl;
	return t_comma;
}

Token* TokenFactory::getPoint() {
	static Token* t_point = NULL;
	if(t_point == NULL) {
		t_point = new Token(Token::T_POINT);
	}
	cout << "point" << endl;
	return t_point;
}

Token* TokenFactory::getOr() {
	static Token* t_or = NULL;
	if(t_or == NULL) {
		t_or = new Token(Token::T_OR);
	}
	cout << "or" << endl;
	return t_or;
}

Token* TokenFactory::getAnd() {
	static Token* t_and = NULL;
	if(t_and == NULL) {
		t_and = new Token(Token::T_AND);
	}
	cout << "and" << endl;
	return t_and;
}

Token* TokenFactory::getNot() {
	static Token* t_not = NULL;
	if(t_not == NULL) {
		t_not = new Token(Token::T_NOT);
	}
	cout << "not" << endl;
	return t_not;
}

Token* TokenFactory::getEq() {
	static Token* t_eq = NULL;
	if(t_eq == NULL) {
		t_eq = new Token(Token::T_EQ);
	}
	cout << "eq" << endl;
	return t_eq;
}

Token* TokenFactory::getNe() {
	static Token* t_ne = NULL;
	if(t_ne == NULL) {
		t_ne = new Token(Token::T_NE);
	}
	cout << "ne" << endl;
	return t_ne;
}

Token* TokenFactory::getLt() {
	static Token* t_lt = NULL;
	if(t_lt == NULL) {
		t_lt = new Token(Token::T_LT);
	}
	cout << "lt" << endl;
	return t_lt;
}

Token* TokenFactory::getLe() {
	static Token* t_le = NULL;
	if(t_le == NULL) {
		t_le = new Token(Token::T_LE);
	}
	cout << "le" << endl;
	return t_le;
}

Token* TokenFactory::getGt() {
	static Token* t_gt = NULL;
	if(t_gt == NULL) {
		t_gt = new Token(Token::T_GT);
	}
	cout << "gt" << endl;
	return t_gt;
}

Token* TokenFactory::getGe() {
	static Token* t_ge = NULL;
	if(t_ge == NULL) {
		t_ge = new Token(Token::T_GE);
	}
	cout << "ge" << endl;
	return t_ge;
}

Token* TokenFactory::getAssig() {
	static Token* t_assig = NULL;
	if(t_assig == NULL) {
		t_assig = new Token(Token::T_ASSIG);
	}
	cout << "assig" << endl;
	return t_assig;
}

Token* TokenFactory::getPlus() {
	static Token* t_plus = NULL;
	if(t_plus == NULL) {
		t_plus = new Token(Token::T_PLUS);
	}
	cout << "plus" << endl;
	return t_plus;
}

Token* TokenFactory::getMinus() {
	static Token* t_minus = NULL;
	if(t_minus == NULL) {
		t_minus = new Token(Token::T_MINUS);
	}
	cout << "minus" << endl;
	return t_minus;
}

Token* TokenFactory::getTimes() {
	static Token* t_times = NULL;
	if(t_times == NULL) {
		t_times = new Token(Token::T_TIMES);
	}
	cout << "times" << endl;
	return t_times;
}

Token* TokenFactory::getDiv() {
	static Token* t_div = NULL;
	if(t_div == NULL) {
		t_div = new Token(Token::T_DIV);
	}
	cout << "div" << endl;
	return t_div;
}

Token* TokenFactory::getMod() {
	static Token* t_mod = NULL;
	if(t_mod == NULL) {
		t_mod = new Token(Token::T_MOD);
	}
	cout << "mod" << endl;
	return t_mod;
}

Token* TokenFactory::getIdent(char* s) {
	cout << "identifier " << s << endl;
	return new Identifier(s);
}

Token* TokenFactory::getNumber(int i) {
	cout << "number" << i << endl;
	return new Number(i);
}

Token* TokenFactory::getString() {
	static Token* t_string = NULL;
	if(t_string == NULL) {
		t_string = new Token(Token::T_STRING);
	}
	cout << "string" << endl;
	return t_string;
}

Token* TokenFactory::getClass() {
	static Token* t_class = NULL;
	if(t_class == NULL) {
		t_class = new Token(Token::T_CLASS);
	}
	cout << "class" << endl;
	return t_class;
}

Token* TokenFactory::getPublic() {
	static Token* t_public = NULL;
	if(t_public == NULL) {
		t_public = new Token(Token::T_PUBLIC);
	}
	cout << "public" << endl;
	return t_public;
}

Token* TokenFactory::getStatic() {
	static Token* t_static = NULL;
	if(t_static == NULL) {
		t_static = new Token(Token::T_STATIC);
	}
	cout << "static" << endl;
	return t_static;
}

Token* TokenFactory::getVoid() {
	static Token* t_void = NULL;
	if(t_void == NULL) {
		t_void = new Token(Token::T_VOID);
	}
	cout << "void" << endl;
	return t_void;
}

Token* TokenFactory::getMain() {
	static Token* t_main = NULL;
	if(t_main == NULL) {
		t_main = new Token(Token::T_MAIN);
	}
	cout << "main" << endl;
	return t_main;
}

Token* TokenFactory::getInt() {
	static Token* t_int = NULL;
	if(t_int == NULL) {
		t_int = new Token(Token::T_INT);
	}
	cout << "int" << endl;
	return t_int;
}

Token* TokenFactory::getBoolean() {
	static Token* t_boolean = NULL;
	if(t_boolean == NULL) {
		t_boolean = new Token(Token::T_BOOLEAN);
	}
	cout << "boolean" << endl;
	return t_boolean;
}

Token* TokenFactory::getWhile() {
	static Token* t_while = NULL;
	if(t_while == NULL) {
		t_while = new Token(Token::T_WHILE);
	}
	cout << "while" << endl;
	return t_while;
}

Token* TokenFactory::getIf() {
	static Token* t_if = NULL;
	if(t_if == NULL) {
		t_if = new Token(Token::T_IF);
	}
	cout << "if" << endl;
	return t_if;
}

Token* TokenFactory::getElse() {
	static Token* t_else = NULL;
	if(t_else == NULL) {
		t_else = new Token(Token::T_ELSE);
	}
	cout << "else" << endl;
	return t_else;
}

Token* TokenFactory::getSystem() {
	static Token* t_system = NULL;
	if(t_system == NULL) {
		t_system = new Token(Token::T_SYSTEM);
	}
	cout << "system" << endl;
	return t_system;
}

Token* TokenFactory::getOut() {
	static Token* t_out = NULL;
	if(t_out == NULL) {
		t_out = new Token(Token::T_OUT);
	}
	cout << "out" << endl;
	return t_out;
}

Token* TokenFactory::getPrintln() {
	static Token* t_println = NULL;
	if(t_println == NULL) {
		t_println = new Token(Token::T_PRINTLN);
	}
	cout << "println" << endl;
	return t_println;
}

Token* TokenFactory::getReturn() {
	static Token* t_return = NULL;
	if(t_return == NULL) {
		t_return = new Token(Token::T_RETURN);
	}
	cout << "return" << endl;
	return t_return;
}

Token* TokenFactory::getNull() {
	static Token* t_null = NULL;
	if(t_null == NULL) {
		t_null = new Token(Token::T_NULL);
	}
	cout << "null" << endl;
	return t_null;
}

Token* TokenFactory::getFalse() {
	static Token* t_false = NULL;
	if(t_false == NULL) {
		t_false = new Token(Token::T_FALSE);
	}
	cout << "false" << endl;
	return t_false;
}

Token* TokenFactory::getTrue() {
	static Token* t_true = NULL;
	if(t_true == NULL) {
		t_true = new Token(Token::T_TRUE);
	}
	cout << "true" << endl;
	return t_true;
}

Token* TokenFactory::getThis() {
	static Token* t_this = NULL;
	if(t_this == NULL) {
		t_this = new Token(Token::T_THIS);
	}
	cout << "this" << endl;
	return t_this;
}

Token* TokenFactory::getNew() {
	static Token* t_new = NULL;
	if(t_new == NULL) {
		t_new = new Token(Token::T_NEW);
	}
	cout << "new" << endl;
	return t_new;
}

Token* TokenFactory::getWhitespace() {
	static Token* t_whitespace = NULL;
	if(t_whitespace == NULL) {
		t_whitespace = new Token(Token::T_WHITESPACE);
	}
	cout << "whitespace" << endl;
	return t_whitespace;
}

Token* TokenFactory::getComment() {
	static Token* t_comment = NULL;
	if(t_comment == NULL) {
		t_comment = new Token(Token::T_COMMENT);
	}
	cout << "comment" << endl;
	return t_comment;
}

Token* TokenFactory::getError() {
	static Token* t_error = NULL;
	if(t_error == NULL) {
		t_error = new Token(Token::T_ERROR);
	}
	cout << "error" << endl;
	return t_error;
}

