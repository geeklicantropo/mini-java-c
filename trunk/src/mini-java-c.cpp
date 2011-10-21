//============================================================================
// Name        : mjavac.cpp
//============================================================================

#include <iostream>

#include "scanner/Scanner.h"
#include "scanner/Screener.h"

using namespace std;

int main() {

	Scanner* scanner = new Scanner("test");
	Screener* screener = new Screener(scanner);

	Token* token;
	for (token = screener->nextToken(); token->getTag() != Token::T_EOF; token = screener->nextToken()) {
		cout << "test" << endl;
	}
	return 0;
}
