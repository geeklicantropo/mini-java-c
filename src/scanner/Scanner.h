/*
 * Scanner.h
 *
 *  Created on: Oct 21, 2011
 *      Author: michaelbohn
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include <string>
#include <fstream>
#include "Token.h"

class Scanner {
public:
	Scanner(std::string);
	virtual ~Scanner();
	Token* nextToken();
private:
	enum State {
		ERR,
		START,
	};

	std::string fFile;
	std::ifstream* fInput;

	bool isFinal(Scanner::State);
	Scanner::State transition(Scanner::State, char c);
	Token* makeToken(Scanner::State, std::string);
};

#endif /* SCANNER_H_ */
