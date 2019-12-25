//
// Created by yanivmadmon on 05/11/2019.
//

#include "ex1.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <iterator>
#include <map>
#include <bits/stdc++.h>


using namespace std;


Variable& Variable::operator++(){
   this->value++;
    return *this;
}
Variable& Variable::operator--(){
   this->value--;
    return *this;
}
Variable& Variable::operator+=(double num){
    this->value = this->value + num;
    return *this;

}
Variable& Variable::operator-=(double num){
    this-> value = this->value - num;
    return *this;
}
Variable& Variable::operator++(int){
    this->value++;
    return *this;
}
Variable& Variable::operator--(int){
    this->value--;
    return *this;
}
double Variable::GetValue(){
    double val = this->value;
    return val;
}
string Variable::GetString(){
    string s = this->str;
    return s;
}
double Variable:: calculate(){
    return this->value;
}
double Plus:: calculate(){
 return left->calculate() + right->calculate();
}
double Minus:: calculate(){
    return left->calculate() - right->calculate();
}
double Mul:: calculate(){
    return left->calculate() * right->calculate();
}
double Div:: calculate(){
    if ((right->calculate() == 0)){
            throw "Error: divided by 0";
    }
    return left->calculate() / right->calculate();
}
double UPlus:: calculate(){
    return ex->calculate();
}
double UMinus:: calculate(){
    return ex->calculate()*(-1);
}
double Value:: calculate(){
    double val = value;
    return val;
}
Expression* Interpreter:: interpret(string infix){
    std::queue<string> myqueue;
    std::stack<string> mystack;
    std::stack<Expression*> myexp;

    infix = insertVariables(infix);

    infix = unaryOp(infix);
    checkInput (infix);
    for ( unsigned int j = 0 ; j < infix.length(); j++) {
        if (numbers(infix.substr(j,1))){
            string strNum;
            int k = 0;
            while (numbers(infix.substr(j,1))||infix.substr(j,1) == "." ){
                k++;
                j++;
            }
            strNum= infix.substr(j-k,k);
            myqueue.push(strNum);
            j--;
        }
        else if (infix.at(j) == '(') {
            mystack.push(infix.substr(j,1));
        }
        else if (infix.at(j) == ')') {
            while (!mystack.empty() && mystack.top() != "(") {
                myqueue.push(mystack.top());
                mystack.pop();
            }
            mystack.pop();
        }
        else if ((infix.at(j) == '+') || (infix.at(j) == '-') || (infix.at(j) == '*') || (infix.at(j) == '/')||
                (infix.at(j) == '$') || (infix.at(j) == '#')) {
                if ((infix.at(j+1) == '+') || (infix.at(j+1) == '-') || (infix.at(j+1) == '*') || (infix.at(j+1) == '/')||
                    (infix.at(j+1) == '$') || (infix.at(j+1) == '#')) {
                    throw "Error : Invalid input";
            }
            while (!mystack.empty() && strong(mystack.top()) >= strong(infix.substr(j,1))) {
                myqueue.push(mystack.top());
                mystack.pop();
            }
            mystack.push(infix.substr(j,1));
        }
    }
        while(!mystack.empty()){
            myqueue.push(mystack.top());
            mystack.pop();
        }

    Expression* exp = nullptr ;
    Expression* left;
    Expression* right;
    while(!myqueue.empty()) {
        if ((myqueue.front() == "+") || (myqueue.front() == "-") || (myqueue.front() == "*") ||
            (myqueue.front() == "/")) {

            right = myexp.top();
            myexp.pop();
            left = myexp.top();
            myexp.pop();

            if (myqueue.front() == "+") {
                exp = new Plus(left, right);
            }
            if (myqueue.front() == "-") {
                exp = new Minus(left, right);
            }
            if (myqueue.front() == "*") {
                exp = new Mul(left, right);
            }
            if (myqueue.front() == "/") {
                exp = new Div(left, right);
            }
        } else if ((myqueue.front() == "$") || (myqueue.front() == "#")) {
            if (myqueue.front() == "$") {
                exp = new UMinus(myexp.top());
                myexp.pop();
            }
            if (myqueue.front() == "#") {
                exp = new UPlus(myexp.top());
                myexp.pop();
            }
        } else {
            stringstream str(myqueue.front());
            double x;
            str >> x;
            exp = new Value(x);
        }
        myqueue.pop();
        myexp.push(exp);
    }
        return myexp.top();
}
string Interpreter:: insertVariables(string s){
    for (auto const& pair: parmeters) {
        string value = pair.second->getValue();
        string var = pair.first;
        if (s.find(var) != std::string::npos) {
            for (unsigned int i = 0; i < s.size(); i++) {
                string sub = s.substr(i);
                int index = sub.find(var);
                if (index >= 0) {
                    s.replace(i + index, var.size(), value);
                }
            }
        }
    }
    return s;
}
bool Interpreter:: numbers(string s){
    string numbers = "0123456789";
    for (unsigned int i =0; i< numbers.size() ; i++){
        if(s == numbers.substr(i,1)){
            return true;
        }
    }
    return false;
}
int Interpreter:: strong(string op){
    if ((op == "+")||(op == "-")){
        return 1;
    }
    else if ((op == "*")||(op == "/")) {
        return 2;
    }
    else if((op == "$")||(op == "#")) {
        return 3;
    }
    else if((op == ")")||(op == "(")) {
        return -1;
    }
    else {return 0;}
}
string Interpreter:: unaryOp(string infix){
    for (unsigned int i = 0 ; i<infix.length()-1; i++){
        if (infix.at(i) == '-'){
            if (i == 0){
                infix.at(i) = '$';
            }
            else if ((!numbers(infix.substr(i-1,1)))){
                if((infix.at(i-1) == '(')){
                    infix.at(i) = '$';

                }
            }
        }
        if (infix.at(i) == '+'){
            if (i == 0){
                infix.at(i) = '#';
            }
            else if (!numbers(infix.substr(i-1,1))){
                if((infix.at(i-1) == '(')){
                    infix.at(i) = '#';

                }
            }
        }
    }
    return infix;
}
void Interpreter:: checkInput(string s){
    string numbers = "0123456789";
    string op = "+-/*$#().";
    int close =0;
    int open =0;
    if (s.empty()){
        throw "Error : Invalid input";

    }
    for ( unsigned int i = 0 ; i< s.size(); i++){
        if (s.substr(i,1) == "("){
            open++;
        }
        if (s.substr(i,1) == ")"){
            close++;
        }
       if ((numbers.find(s.substr(i,1)) == std::string::npos)&&
               (op.find(s.substr(i,1)) == std::string::npos))
            throw "Error : Invalid input";
    }
    if (close != open){
        throw "Error : Invalid input";
    }
}
