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
			Q1,
			Q2,
	};

	std::string fFile;
	std::ifstream* fInput;
	bool fEOF;

	Token* handleEOF(Scanner::State, std::streampos, std::streampos);
	char* extractText(std::ifstream* stream, std::streampos, std::streampos);

	Scanner::State getStartState();
	bool isFinal(Scanner::State);
	Scanner::State transition(Scanner::State, char);
	Token* makeToken(Scanner::State, char*);
};

#endif /* SCANNER_H_ */
