#ifndef __EXPR_H__
#define __EXPR_H__
#include <string>


class Expr {

   public:
	virtual int eval() const = 0;
	virtual std::string prettyPrint() const = 0;
	virtual ~Expr();

};

#endif
