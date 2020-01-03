//
// Created by yanivmadmon on 05/11/2019.
//

#ifndef EX1_EX1_H
#define EX1_EX1_H
#include "Expression.h"
#include "Var.h"
#include <string>
#include <iterator>
#include <map>


using namespace std;

class BinaryOperator : public Expression{
protected:
    Expression* right;
    Expression* left;
};
class Plus :public BinaryOperator {
public:
    Plus(Expression* l , Expression* r){ this->left = l ; this->right = r;};
    virtual ~Plus() {delete(right); delete(left);};
    double calculate();
};
class Minus :public BinaryOperator {
public:
    Minus(Expression* l , Expression* r){this->left=l; this->right=r;};
    virtual ~Minus() {delete(right); delete(left);};

    double calculate();
};
class Mul :public BinaryOperator {
public:
    Mul(Expression* l , Expression* r){this->left=l; this->right=r;};
    virtual ~Mul() {delete(right); delete(left);};
    double calculate();
};
class Div :public BinaryOperator {
public:
    Div(Expression* l , Expression* r){this->left=l; this->right=r;};
    virtual ~Div() {delete(right); delete(left);};
    double calculate();
};
class Value : public Expression{
private:
    double value;
public:
    Value(double val) : value(val){};
    double calculate();
};
class Variable : public Expression{
private:
    double value;
    string str;
public:
    Variable(string s, double v){ this->str = s; this->value = v;};
    Variable& operator++();
    Variable& operator--();
    Variable& operator+=(double);
    Variable& operator-=(double);
    Variable& operator++(int);
    Variable& operator--(int);
    double calculate();
    double GetValue();
    string GetString();
};
class UnaryOperator: public Expression{
protected:
    Expression* ex;
};
class UPlus: public UnaryOperator{
public:
    UPlus (Expression* p){this->ex = p;};
    virtual ~UPlus() {delete(ex);};
    double calculate();
};
class UMinus: public UnaryOperator{
public:
    UMinus (Expression* p){this->ex = p;};
    virtual ~UMinus() {delete(ex);};
    double calculate();
};
//par 2
class Interpreter {
    unordered_map <string,Var*>* parmeters ;

public:
    Interpreter(unordered_map <string,Var*>* symbolTable){this->parmeters = symbolTable;};
    Expression* interpret(string s);

    int strong(string op);
    string removeSpaces(string infix);
    bool numbers(string c);
    void checkInput(string s);
    string unaryOp(string infix);
    string insertVariables(string s);
};

#endif //EX1_EX1_H
