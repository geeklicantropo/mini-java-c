//============================================================================
// Name        : mjavac.cpp
//============================================================================

#include <iostream>

#include "scanner/Scanner.h"
#include "scanner/Screener.h"

using namespace std;

int main(int argc, const char* argv[]) {

	if(argc != 2) {
		return -1;
	}

	string input = string(argv[1]);

	Scanner* scanner = new Scanner(input);
	Screener* screener = new Screener(scanner);

	//Test: read all tokens
	Token* token;
	for (token = screener->nextToken(); token->getTag() != Token::T_EOF; token = screener->nextToken()) {
		//cout << "test" << endl;
	}
	return 0;
}
