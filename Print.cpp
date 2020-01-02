//
// Created by yanivmadmon on 12/21/19.
//

#include "Print.h"
#include "ex1.h"

int Print:: execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>* queueMas,unordered_map <string,Var*>* symbolTable){
    auto itr = symbolTable->find(data[index+1]);
    string finalStr = data[index+1];
    if (itr != symbolTable->end() ){
        finalStr = doInter(data[index+1],symbolTable);
    }
    std::cout << finalStr << std::endl;
    return 2;
}
string Print:: doInter(string str,unordered_map <string,Var*>* symbolTable){
    Interpreter* inter = new Interpreter(symbolTable);
    Expression* exp =  inter->interpret(str);
    double num = exp->calculate();
    auto finalStr = std::to_string(num);
    return finalStr;
}