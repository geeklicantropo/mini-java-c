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

Token::Tag Token::getTag() const {
	return fTag;
}

Token::~Token() {
}


std::ostream& operator<<(std::ostream& aStream, const Token& aToken)
{
  switch(aToken.getTag()) {
        case Token::T_EOF:
            aStream << "";
        break;

		case Token::T_LPAREN:
            aStream << "(";
		break;

		case Token::T_RPAREN:
            aStream << ")";
		break;

        case Token::T_LCURLYPAREN:
            aStream << "{";
		break;

        case Token::T_RCURLYPAREN:
            aStream << "}";
		break;


        case Token::T_LSQPAREN:
            aStream << "[";
		break;


        case Token::T_RSQPAREN:
            aStream << "]";
		break;


        case Token::T_SEMICOLON:
            aStream << ";";
		break;

        case Token::T_COMMA:
            aStream << ",";
		break;

        case Token::T_POINT:
            aStream << ".";
		break;

        case Token::T_OR:
            aStream << "||";
		break;

        case Token::T_AND:
            aStream << "&&";
		break;

        case Token::T_NOT:
            aStream << "!";
		break;

        case Token::T_EQ:
            aStream << "==";
		break;

        case Token::T_NE:
            aStream << "!=";
		break;

        case Token::T_LT:
            aStream << "<";
		break;

        case Token::T_LE:
            aStream << "<=";
		break;

        case Token::T_GT:
            aStream << ">";
		break;

        case Token::T_GE:
            aStream << ">=";
		break;

        case Token::T_ASSIG:
            aStream << "=";
		break;

        case Token::T_PLUS:
            aStream << "+";
		break;

        case Token::T_MINUS:
            aStream << "-";
		break;

        case Token::T_TIMES:
            aStream << "*";
		break;

        case Token::T_DIV:
            aStream << "/";
		break;

        case Token::T_MOD:
            aStream << "%";
		break;

        case Token::T_IDENT:
            aStream << "";
		break;

		case Token::T_NUMBER:
            aStream << "";
		break;

		case Token::T_STRING:
            aStream << "String";
		break;

		case Token::T_CLASS:
            aStream << "class";
		break;

		case Token::T_PUBLIC:
            aStream << "public";
		break;

		case Token::T_STATIC:
            aStream << "static";
		break;

		case Token::T_VOID:
            aStream << "void";
		break;

		case Token::T_MAIN:
            aStream << "main";
		break;

		case Token::T_INT:
            aStream << "int";
		break;

		case Token::T_BOOLEAN:
            aStream << "boolean";
		break;

		case Token::T_WHILE:
            aStream << "while";
		break;

		case Token::T_IF:
            aStream << "if";
		break;

		case Token::T_ELSE:
            aStream << "else";
		break;

		case Token::T_SYSTEM:
            aStream << "System";
		break;

		case Token::T_OUT:
            aStream << "out";
		break;

		case Token::T_PRINTLN:
            aStream << "println";
		break;

		case Token::T_RETURN:
            aStream << "return";
		break;

		case Token::T_NULL:
            aStream << "NULL";
		break;

		case Token::T_FALSE:
            aStream << "false";
		break;

		case Token::T_TRUE:
            aStream << "true";
		break;

		case Token::T_THIS:
            aStream << "this";
		break;

		case Token::T_NEW:
            aStream << "new";
		break;

		case Token::T_WHITESPACE:
            aStream << "";
		break;

		case Token::T_COMMENT:
            aStream << "";
		break;

		case Token::T_ERROR:
            aStream << "Token: ERROR";
		break;


    };

 return aStream;
}
