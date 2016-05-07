#ifndef BINARY_H
#define BINARY_H

#include "expr.h"
#include <string>
using std::string;


class BinExp : public Expr { // binary expression
	
	const string op; // operator
	const Expr *leftArg; // left operand
	const Expr *rightArg; // right operand
  public :
	BinExp( const string &oper, Expr *left, Expr *right );	
	~BinExp();
	int eval() const;
	string prettyPrint() const;
};
#endif

