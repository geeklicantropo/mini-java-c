/*
 * Number.h
 *
 *  Created on: 23.10.2011
 *      Author: barbara
 */

#ifndef NUMBER_H_
#define NUMBER_H_

#include "Token.h"

class Number: public Token {
public:
	Number(int i);
	virtual ~Number();
	int getNumber();

private:
	int number;
};

#endif /* NUMBER_H_ */
