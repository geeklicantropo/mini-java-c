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

Screener::State Screener::transition(Screener::State current, char c) {
	if(current == Screener::p78) {
		if(c == 'c') {
			return Screener::p86;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p79) {
		return Screener::ERR;
	} else if(current == Screener::p30) {
		if(c == 'a') {
			return Screener::p49;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p31) {
		if(c == 'i') {
			return Screener::p50;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p32) {
		if(c == 'u') {
			return Screener::p51;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p33) {
		if(c == 'i') {
			return Screener::p52;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p73) {
		if(c == 'c') {
			return Screener::p83;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p35) {
		if(c == 's') {
			return Screener::p54;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p72) {
		if(c == 'l') {
			return Screener::p82;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p34) {
		if(c == 'i') {
			return Screener::p53;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p71) {
		if(c == 'n') {
			return Screener::p81;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p37) {
		return Screener::ERR;
	} else if(current == Screener::p36) {
		if(c == 'r') {
			return Screener::p55;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p70) {
		if(c == 'e') {
			return Screener::p80;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p39) {
		if(c == 'l') {
			return Screener::p56;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p77) {
		if(c == 'n') {
			return Screener::p85;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p38) {
		return Screener::ERR;
	} else if(current == Screener::p76) {
		return Screener::ERR;
	} else if(current == Screener::p75) {
		return Screener::ERR;
	} else if(current == Screener::p74) {
		if(c == 'a') {
			return Screener::p84;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p0) {
		if(c == 'o') {
			return Screener::p6;
		} else if(c == 'e') {
			return Screener::p10;
		} else if(c == 'b') {
			return Screener::p7;
		} else if(c == 'r') {
			return Screener::p11;
		} else if(c == 'S') {
			return Screener::p16;
		} else if(c == 'n') {
			return Screener::p3;
		} else if(c == 'p') {
			return Screener::p5;
		} else if(c == 'm') {
			return Screener::p4;
		} else if(c == 'i') {
			return Screener::p2;
		} else if(c == 'v') {
			return Screener::p14;
		} else if(c == 'w') {
			return Screener::p15;
		} else if(c == 'c') {
			return Screener::p8;
		} else if(c == 's') {
			return Screener::p12;
		} else if(c == 'f') {
			return Screener::p9;
		} else if(c == 't') {
			return Screener::p13;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p6) {
		if(c == 'u') {
			return Screener::p24;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p5) {
		if(c == 'u') {
			return Screener::p23;
		} else if(c == 'r') {
			return Screener::p22;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p8) {
		if(c == 'l') {
			return Screener::p26;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p7) {
		if(c == 'o') {
			return Screener::p25;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p2) {
		if(c == 'f') {
			return Screener::p18;
		} else if(c == 'n') {
			return Screener::p17;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p4) {
		if(c == 'a') {
			return Screener::p21;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p3) {
		if(c == 'u') {
			return Screener::p20;
		} else if(c == 'e') {
			return Screener::p19;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p67) {
		return Screener::ERR;
	} else if(current == Screener::p68) {
		return Screener::ERR;
	} else if(current == Screener::p69) {
		if(c == 'e') {
			return Screener::p79;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p21) {
		if(c == 'i') {
			return Screener::p40;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p22) {
		if(c == 'i') {
			return Screener::p41;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p9) {
		if(c == 'a') {
			return Screener::p27;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p20) {
		if(c == 'l') {
			return Screener::p39;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p60) {
		if(c == 'e') {
			return Screener::p74;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p26) {
		if(c == 'a') {
			return Screener::p45;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p25) {
		if(c == 'o') {
			return Screener::p44;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p62) {
		if(c == 'e') {
			return Screener::p76;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p24) {
		if(c == 't') {
			return Screener::p43;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p61) {
		if(c == 's') {
			return Screener::p75;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p23) {
		if(c == 'b') {
			return Screener::p42;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p64) {
		if(c == 'r') {
			return Screener::p77;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p63) {
		return Screener::ERR;
	} else if(current == Screener::p29) {
		if(c == 't') {
			return Screener::p48;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p66) {
		return Screener::ERR;
	} else if(current == Screener::p28) {
		if(c == 's') {
			return Screener::p47;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p27) {
		if(c == 'l') {
			return Screener::p46;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p65) {
		if(c == 'i') {
			return Screener::p78;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p10) {
		if(c == 'l') {
			return Screener::p28;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p11) {
		if(c == 'e') {
			return Screener::p29;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p58) {
		if(c == 't') {
			return Screener::p72;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p59) {
		if(c == 'i') {
			return Screener::p73;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p56) {
		return Screener::ERR;
	} else if(current == Screener::p57) {
		return Screener::ERR;
	} else if(current == Screener::p17) {
		if(c == 't') {
			return Screener::p37;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p55) {
		if(c == 'i') {
			return Screener::p71;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p90) {
		return Screener::ERR;
	} else if(current == Screener::p16) {
		if(c == 'y') {
			return Screener::p35;
		} else if(c == 't') {
			return Screener::p36;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p54) {
		if(c == 't') {
			return Screener::p70;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p19) {
		if(c == 'w') {
			return Screener::p38;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p53) {
		if(c == 'l') {
			return Screener::p69;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p18) {
		return Screener::ERR;
	} else if(current == Screener::p52) {
		if(c == 'd') {
			return Screener::p68;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p13) {
		if(c == 'h') {
			return Screener::p31;
		} else if(c == 'r') {
			return Screener::p32;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p51) {
		if(c == 'e') {
			return Screener::p67;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p12) {
		if(c == 't') {
			return Screener::p30;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p50) {
		if(c == 's') {
			return Screener::p66;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p15) {
		if(c == 'h') {
			return Screener::p34;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p14) {
		if(c == 'o') {
			return Screener::p33;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p89) {
		return Screener::ERR;
	} else if(current == Screener::p49) {
		if(c == 't') {
			return Screener::p65;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p45) {
		if(c == 's') {
			return Screener::p61;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p46) {
		if(c == 's') {
			return Screener::p62;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p47) {
		if(c == 'e') {
			return Screener::p63;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p48) {
		if(c == 'u') {
			return Screener::p64;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p42) {
		if(c == 'l') {
			return Screener::p59;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p41) {
		if(c == 'n') {
			return Screener::p58;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p44) {
		if(c == 'l') {
			return Screener::p60;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p43) {
		return Screener::ERR;
	} else if(current == Screener::p80) {
		if(c == 'm') {
			return Screener::p87;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p40) {
		if(c == 'n') {
			return Screener::p57;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p85) {
		return Screener::ERR;
	} else if(current == Screener::p86) {
		return Screener::ERR;
	} else if(current == Screener::p87) {
		return Screener::ERR;
	} else if(current == Screener::p88) {
		return Screener::ERR;
	} else if(current == Screener::p81) {
		if(c == 'g') {
			return Screener::p88;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p82) {
		if(c == 'n') {
			return Screener::p89;
		} else {
			return Screener::ERR;
		}
	} else if(current == Screener::p83) {
		return Screener::ERR;
	} else if(current == Screener::p84) {
		if(c == 'n') {
			return Screener::p90;
		} else {
			return Screener::ERR;
		}
	}
	return Screener::ERR;
}

Token* Screener::screenForKeywords(Identifier* ident) {

		int currentPos = 0;
		State current = this->getStartState();
		State lastFinal = Screener::ERR;
		Token* foundToken = NULL;
		char* content = ident->getIdentifier();

		int c = content[currentPos];
		while(c != 0) {
				current = transition(current, c);

				if(isFinal(current)) {
								lastFinal = current;
				}
				currentPos++;
				c = content[currentPos];
		}

		if(lastFinal != Screener::ERR) {
			foundToken = makeToken(lastFinal);
		}

		if(foundToken){
			return foundToken;
		} else {
			cout << "IDENT " << ident->getIdentifier() << endl;
			return ident;
		}
		//invariant: foundToken != NULL
		//return foundToken;
}

bool Screener::isFinal(Screener::State state) {
	return state == p79 || state == p37 || state == p38 || state == p76 || state == p75 || state == p67 || state == p68 || state == p63 || state == p66 || state == p56 || state == p57 || state == p90 || state == p18 || state == p89 || state == p43 || state == p85 || state == p86 || state == p87 || state == p88 || state == p83;
}

Screener::State Screener::getStartState() {
	return Screener::p0;
}

Token* Screener::makeToken(Screener::State state) {
	assert(isFinal(state));

	if (state == Screener::p56) {
		return TokenFactory::getNull();
	} else if(state == Screener::p38) {
		return TokenFactory::getNew();
	} else if(state == Screener::p86) {
		return TokenFactory::getStatic();
	} else if(state == Screener::p43) {
		return TokenFactory::getOut();
	} else if(state == Screener::p63) {
		return TokenFactory::getElse();
	} else if(state == Screener::p18) {
		return TokenFactory::getIf();
	} else if(state == Screener::p37) {
		return TokenFactory::getInt();
	} else if(state == Screener::p90) {
		return TokenFactory::getBoolean();
	} else if(state == Screener::p67) {
		return TokenFactory::getTrue();
	} else if(state == Screener::p66) {
		return TokenFactory::getThis();
	} else if(state == Screener::p76) {
		return TokenFactory::getFalse();
	} else if(state == Screener::p85) {
		return TokenFactory::getReturn();
	} else if(state == Screener::p75) {
		return TokenFactory::getClass();
	} else if(state == Screener::p87) {
		return TokenFactory::getSystem();
	} else if(state == Screener::p88) {
		return TokenFactory::getString();
	} else if(state == Screener::p68) {
		return TokenFactory::getVoid();
	} else if(state == Screener::p89) {
		return TokenFactory::getPrintln();
	} else if(state == Screener::p83) {
		return TokenFactory::getPublic();
	} else if(state == Screener::p79) {
		return TokenFactory::getWhile();
	} else if(state == Screener::p57) {
		return TokenFactory::getMain();
	} else {
		return NULL;
	}
}

