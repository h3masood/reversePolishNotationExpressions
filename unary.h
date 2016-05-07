#ifndef UNARY_H
#define UNARY_H

#include "expr.h"
#include <string>
using std::string;

class UnExp : public Expr { // unary expression
     
     const string op; // operator
     const Expr *arg; // argument
  public :
	UnExp( const string &s, Expr *exp );
     	~UnExp();
	int eval() const; 
     	string prettyPrint() const;

};

#endif
