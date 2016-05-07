#include "unary.h"
#include <string>
#include <iostream>
using namespace std;


UnExp::UnExp( const string &s, Expr *exp ) : op( s ), arg( exp ) {}


UnExp::~UnExp()
{
	delete arg;
}

int UnExp::eval() const
{   
	if ( op ==  "NEG" ) { 
 		return -1 * arg->eval();
        }   
        else {   
               int ans = arg->eval();
               return ans >= 0 ? ans : -ans;
        }   
} 


string UnExp::prettyPrint() const
{   
	string exprStr; // expression string
	if ( op == "NEG" ) { 
        	exprStr  = "-" + arg->prettyPrint();
        }   
        else {
                exprStr  = "|" + arg->prettyPrint() + "|";
        }   
        return exprStr;
}   
  

