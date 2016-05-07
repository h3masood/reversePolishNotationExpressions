#include "expr.h"
#include "num.h"
#include "binary.h"
#include "unary.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;


// STACK
struct Stack {
     
	unsigned int length; // number of expr objects in stack
	const unsigned int SIZE; // max capacity of stack
     	Expr **aexpr; // array of Expr pointers

	Stack() : SIZE( 10 ) // default constructor
	{
		length = 0;
		aexpr = new Expr *[SIZE];
	}
	
	
	void push( Expr *exp ) // add one to stack
	{
		aexpr[length] = exp;
		length++;
	}


	Expr *pop() // remove one from stack
	{
		length--;
		Expr *exp = aexpr[length];
		return exp;
	}

	~Stack() 
	{
		delete aexpr[0];
		delete [] aexpr; // deallocate heap memory
	}	
};


int main( void )
{
	int val; // number
	string str; // operator
	Stack stk; // expression
	
	// Begin building expression
	while( true ) {
		if ( ( cin >> str ) == 0 ) break; // end of input
		istringstream buffer( str ); 
		if ( buffer >> val ) { // integer read success?
			IntConst *number = new IntConst( val );
			stk.push( number );
		}
		else { // string read
				if ( str == "ABS" || str == "NEG" ) {
					if ( stk.length == 0 ) continue; // ignore  
					Expr *arg = stk.pop(); // get arg
					UnExp *Uexpr = new UnExp( str, arg ); // build unary expression
					stk.push( Uexpr );
				}
				else {
					if ( stk.length < 2 ) continue;
					Expr *rightArg = stk.pop(); // get right operand
					Expr *leftArg = stk.pop(); // get left operand
					BinExp *bexpr = new BinExp( str, leftArg, rightArg );
					stk.push( bexpr );
				}
		}

		if ( stk.length > stk.SIZE ) { // enough capacity ? 
			cerr << "Stack overflow" << endl;
			return( EXIT_FAILURE );
		}
	} // while
	// expression built

	// print expression
	int exprResult = stk.aexpr[0]->eval();
	if ( exprResult < 0 ) cout << "(";
	if ( stk.length == 1 ) {
		cout << stk.aexpr[0]->prettyPrint() << endl;
		if ( exprResult < 0 ) cout << ")";
		cout << "= " << exprResult << endl;
	}
	else {
		cout << stk.aexpr[stk.length-1]->prettyPrint() << endl;
		if ( exprResult < 0 ) cout << ")";
		cout << "= " << exprResult << endl;
	}
	// print complete

	return( EXIT_SUCCESS );
}


