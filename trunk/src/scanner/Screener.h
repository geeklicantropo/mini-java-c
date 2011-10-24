/*
 * Screener.h
 *
 *  Created on: Oct 21, 2011
 *      Author: michaelbohn
 */

#ifndef SCREENER_H_
#define SCREENER_H_

#include "Token.h"
#include "Scanner.h"
#include "Identifier.h"

class Screener {
public:
	Screener(Scanner*);
	virtual ~Screener();

	Token* nextToken();
	Token* screenForKeywords(Identifier* ident);
private:
	enum State {
		p78,
		p79,
		p30,
		p31,
		p32,
		p33,
		p73,
		p35,
		p72,
		p34,
		p71,
		p37,
		p36,
		p70,
		p39,
		p77,
		p38,
		p76,
		p75,
		p74,
		p0,
		p6,
		p5,
		p8,
		p7,
		p2,
		p4,
		p3,
		p67,
		p68,
		p69,
		p21,
		p22,
		p9,
		p20,
		p60,
		p26,
		p25,
		p62,
		p24,
		p61,
		p23,
		p64,
		p63,
		p29,
		p66,
		p28,
		p27,
		p65,
		p10,
		p11,
		p58,
		p59,
		p56,
		p57,
		p17,
		p55,
		p90,
		p16,
		p54,
		p19,
		p53,
		p18,
		p52,
		p13,
		p51,
		p12,
		p50,
		p15,
		p14,
		p89,
		p49,
		p45,
		p46,
		p47,
		p48,
		p42,
		p41,
		p44,
		p43,
		p80,
		p40,
		p85,
		p86,
		p87,
		p88,
		p81,
		p82,
		p83,
		p84,
		ERR
	};

	Scanner* fScanner;

	bool isFinal(Screener::State state);
	Screener::State getStartState();
	Screener::State transition(Screener::State current, char c);
	Token* makeToken(Screener::State state);
};

#endif /* SCREENER_H_ */
