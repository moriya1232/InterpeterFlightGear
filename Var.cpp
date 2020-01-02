//
// Created by yanivmadmon on 12/19/19.
//

#include "Var.h"
#include "ex1.h"

int Var :: execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>*queueMas,unordered_map <string,Var*>* symbolTable) {
    string finalStr = doInter(data[index+1],symbolTable);
    this->setValue(finalStr);
    if (this->dir == 'R') {
        //string str = this->sim.substr(1, (str.length() - 1));
       string  str="set " + this->sim +" "+ this->value+"\r\n";
        queueMas->push(str);
    }
    return 2;
}

void Var::setDir(string s) {if (s == "->"){this->dir = 'R';}else{this->dir = 'L';}};
string Var:: doInter(string str,unordered_map <string,Var*>* symbolTable){
    Interpreter* inter = new Interpreter(symbolTable);
    Expression* exp =  inter->interpret(str);
    double num = exp->calculate();
    auto finalStr = std::to_string(num);
    return finalStr;
}