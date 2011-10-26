//============================================================================
// Name        : mjavac.cpp
//============================================================================

#include <iostream>
#include <stdlib.h>

#include "scanner/Scanner.h"
#include "scanner/Screener.h"

using namespace std;

void printErrorAndExit(const char*);
void printUsageAndExit();

bool optToken = false;

int main(int argc, const char* argv[]) {

	string input;

	if(argc == 2) {
		input = string(argv[1]);
	} else if(argc == 3) {
		string option = string(argv[1]);
		if(option.compare("--tokens") == 0) {
			optToken = true;
		} else {
			printUsageAndExit();
		}
		input = string(argv[2]);
	} else {
		printUsageAndExit();
	}

	Scanner* scanner = new Scanner(input);
	Screener* screener = new Screener(scanner);

	try {
		if(optToken) {
			Token* token;
			for (token = screener->nextToken(); token->getTag() != Token::T_EOF; token = screener->nextToken()) {
				//Output Tokens

				if(token->getTag() == Token::T_ERROR) {
					return -1;
				} else  if(token->getTag() == Token::T_COMMENT || token->getTag() == Token::T_WHITESPACE) {
					continue;
				} else if(token->getTag() == Token::T_IDENT) {
					cout << "IDENT " << *((Identifier*) token) << endl;
				} else if(token->getTag() == Token::T_NUMBER) {
					cout << "INTEGER_LITERAL " << *((Number*) token) << endl;
				} else {
					cout << (*token) << endl;
				}
			}
		}
	} catch(const char* err) {
		printErrorAndExit(err);
	}
	return 0;
}

void printErrorAndExit(const char* err) {
	cout << "ERROR: " << err << endl;
	exit(1);
}

void printUsageAndExit() {
	cout << "usage: mjavac [--tokens] file" << endl;
	exit(1);
}
