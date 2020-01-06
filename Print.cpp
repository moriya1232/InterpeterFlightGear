//
// Created by yanivmadmon on 12/21/19.
//

#include "Print.h"
#include "ex1.h"

int Print:: execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>* queueMas,unordered_map <string,Var*>* symbolTable){
  string finalStr;

   if (!(data[index+1].at(0) == '"')) { // check if this is string
       finalStr = doInter(data[index+1],symbolTable); // if this is an expression
   }
   else{
        finalStr = removeS(data[index+1]); // if this is string remove the ""
   }
    std::cout << finalStr << std::endl; // print to the consol
    return 2;
}
string Print:: doInter(string str,unordered_map <string,Var*>* symbolTable){
    // create new interperter and calculate the expression
    Interpreter* inter = new Interpreter(symbolTable);
    Expression* exp =  inter->interpret(str);
    double num = exp->calculate();
    auto finalStr = std::to_string(num);
    return finalStr;
}
string Print::removeS(string infix) {
    string newInfix;
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] != '"') {
            newInfix += infix[i];
        }
    }
    return newInfix;
}