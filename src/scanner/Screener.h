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
#include "Number.h"
#include <vector>

class Screener {
public:


	Screener(Scanner*);
	virtual ~Screener();

	Token* nextToken();
	Token* screenForKeywords(Identifier* ident);
private:
	Scanner* fScanner;
};

#endif /* SCREENER_H_ */
