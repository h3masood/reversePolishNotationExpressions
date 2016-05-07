#include "binary.h"
#include <string>
#include <iostream>
using namespace std;

BinExp::BinExp( const string &oper, Expr *left, Expr *right )
        : op( oper ), leftArg( left ), rightArg( right ) {}


BinExp::~BinExp()
{
	delete leftArg;
        delete rightArg;
}

int BinExp::eval() const
{   
 	if ( op == "+" ) { 
        	return leftArg->eval() + rightArg->eval();
        }   
        else if ( op == "*" ) { 
               	return leftArg->eval() * rightArg->eval();
        }   
        else if ( op == "-" ) { 
                return leftArg->eval() - rightArg->eval();
        }   
        else {
                return leftArg->eval() / rightArg->eval();
        }   
} 


string BinExp::prettyPrint() const
{
	string exprStr; // expression string
        if ( op == "+" ) { 
       		exprStr = "(" + leftArg->prettyPrint() + " + " + rightArg->prettyPrint() + ")";
        }   
        else if ( op == "*" ) { 
                exprStr = "(" + leftArg->prettyPrint() + " * " + rightArg->prettyPrint() + ")";
        }   
        else if ( op == "-" ) { 
                exprStr = "(" + leftArg->prettyPrint() + " - " + rightArg->prettyPrint() + ")";
        }   
        else {
                exprStr = "(" + leftArg->prettyPrint() + " / " + rightArg->prettyPrint() + ")";
        }   
        return exprStr;
}   
 
