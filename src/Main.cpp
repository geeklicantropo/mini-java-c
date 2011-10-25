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
	return 0;
}
