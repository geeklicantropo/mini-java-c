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
		p10,
		p11,
		p30,
		p31,
		p32,
		p33,
		p35,
		p17,
		p34,
		p16,
		p19,
		p36,
		p18,
		p12,
		p15,
		p14,
		p0,
		p5,
		p8,
		p7,
		p2,
		p1,
		p4,
		p3,
		p21,
		p9,
		p22,
		p20,
		p26,
		p25,
		p24,
		p23,
		p29,
		p28,
		p27,
		p13,
		ERR,
	};

	std::string fFile;
	std::ifstream* fInput;
	std::streampos fLastPos;

	//Token* handleEOF(Scanner::State, std::streampos, std::streampos, unsigned int line);
	char* extractText(std::ifstream* stream, std::streampos start, std::streampos end);

	Scanner::State getStartState();
	bool isFinal(Scanner::State);
	Scanner::State transition(Scanner::State, char);
	Token* makeToken(Scanner::State, char*, unsigned int line);
};

#endif /* SCANNER_H_ */
