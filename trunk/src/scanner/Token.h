/*
 * Token.h
 *
 *  Created on: Oct 21, 2011
 *      Author: michaelbohn
 */

#ifndef TOKEN_H_
#define TOKEN_H_

class Token {
public:
	enum Tag {
		T_EOF,
		T_LPAREN,
		//....
	};
	Token(Token::Tag);
	Tag getTag();
	virtual ~Token();
private:
	Tag fTag;
};

#endif /* TOKEN_H_ */
