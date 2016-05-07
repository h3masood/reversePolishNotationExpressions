#include "num.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;


IntConst::IntConst( const unsigned int a ) : val(a) {} // copy constructor

IntConst::~IntConst() {}

int IntConst::eval() const { return val; }


string IntConst::prettyPrint() const
{   
	ostringstream out;
	out << val;
	return out.str();
}   

