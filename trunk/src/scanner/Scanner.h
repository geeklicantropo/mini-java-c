/*
 * Scanner.h
 *
 *  Created on: Oct 21, 2011
 *      Author: michaelbohn
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include <string>
#include "Token.h"

class Scanner {
public:
	Scanner(std::string);
	virtual ~Scanner();
	Token* nextToken();
private:
	std::string fFile;
};

#endif /* SCANNER_H_ */
