#ifndef NUM_H
#define NUM_H

#include "expr.h"
#include <string>
using std::string;


class IntConst : public Expr {
	
	const unsigned int val;
	
   public :
	IntConst( const unsigned int a ); // copy constructor
	~IntConst();
	int eval() const;
	string prettyPrint() const;
};


#endif 

