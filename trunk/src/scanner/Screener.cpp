/*
 * Screener.cpp
 *
 *  Created on: Oct 21, 2011
 *      Author: michaelbohn
 */

#include <assert.h>
#include <stdio.h>
#include <iostream>
#include "Screener.h"
#include "TokenFactory.h"


Screener::Screener(Scanner* scanner) : fScanner(scanner) {

}

Screener::~Screener() {
}



Token* Screener::screenForKeywords(Identifier* ident) {
    	char* content = ident->getIdentifier();

        std::string sContent(content);

        if(!sContent.compare("NULL")){
            return TokenFactory::getNull();
        }

        else if(!sContent.compare("new")){
            return TokenFactory::getNew();
        }

        else if(!sContent.compare("static")){
            return TokenFactory::getStatic();
        }

       /* else if(!sContent.compare("out")){
           	return TokenFactory::getOut();
        }*/

        else if(!sContent.compare("else")){
           	return TokenFactory::getElse();
        }

        else if(!sContent.compare("if")){
           	return TokenFactory::getIf();
        }

        else if(!sContent.compare("int")){
           	return TokenFactory::getInt();
        }

        else if(!sContent.compare("boolean")){
           	return TokenFactory::getBoolean();
        }

        else if(!sContent.compare("true")){
           	return TokenFactory::getTrue();
        }

        else if(!sContent.compare("this")){
           	return TokenFactory::getThis();
        }

        else if(!sContent.compare("false")){
           	return TokenFactory::getFalse();
        }

        else if(!sContent.compare("return")){
           	return TokenFactory::getReturn();
        }

        else if(!sContent.compare("class")){
            return TokenFactory::getClass();
        }

        /*else if(!sContent.compare("System")){
           	return TokenFactory::getSystem();
        }*/

        /*else if(!sContent.compare("String")){
           	return TokenFactory::getString();
        }*/

        else if(!sContent.compare("void")){
           	return TokenFactory::getVoid();
        }

       /* else if(!sContent.compare("println")){
           	return TokenFactory::getPrintln();
        }*/

        else if(!sContent.compare("public")){
           	return TokenFactory::getPublic();
        }

        else if(!sContent.compare("while")){
           	return TokenFactory::getWhile();
        }

       /* else if(!sContent.compare("main")){
           	return TokenFactory::getMain();
        }*/

      //  cout << "IDENT " << ident->getIdentifier() << endl;
        return ident;

}


Token* Screener::nextToken() {
	Token* token = fScanner->nextToken();

	// filter tokens we don't like (comments, whitespace)
	if(token->getTag() == Token::T_COMMENT || token->getTag() == Token::T_WHITESPACE)
		return nextToken();
	if(token->getTag() == Token::T_ERROR) {
		std::cout << "Error token!" << std::endl;
		return token;
	}

	// convert identifiers that are keywords to keyword tokens
	if(token->getTag() == Token::T_IDENT)
		return screenForKeywords((Identifier*) token);

	return token;
}


