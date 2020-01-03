//
// Created by yanivmadmon on 12/23/19.
//

#include "LoopCommand.h"
#include "ex1.h"

int LoopCommand:: execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>* queueMas,unordered_map <string,Var*>* symbolTable){

    index++;
    string con = data[index];
    this->condition = conditionBool(con);
    index+=2;
    int count = index;
    int count1 = 0;
    while (this->condition){
        index -= count1;
        while(data[index] != "}") {
            auto itr = mapCommand->find(data[index]);
            if (itr != mapCommand->end()) {
                Command *c = itr->second;
                index += c->execute(mapCommand, data, index, queueMas,symbolTable);
            } else {
                auto itr = symbolTable->find(data[index]);
                if (itr != symbolTable->end()) {
                    Var *c = itr->second;
                    index += c->execute(mapCommand, data, index, queueMas, symbolTable);
                }
            }
        }
        this->condition = conditionBool(con);

        count1 = index - count;
    }

   return count1+ 4;
}
bool LoopCommand::  conditionBool (string condition){
    string leftCon ;
    string rightCon;
    string op;

    int opPlace = condition.find_first_of("=", 0);
    if (opPlace == -1){
                opPlace = condition.find_first_of(">", 0);
                if (opPlace == -1) {
                    opPlace = condition.find_first_of("<", 0);
                }
                leftCon = condition.substr(0, opPlace - 1);
                rightCon = condition.substr(opPlace + 1);
                op = condition.substr(opPlace, 1);
    }
    else{
        int opPlace = condition.find_first_of("<=", 0);
        if (opPlace == -1) {
            int opPlace = condition.find_first_of("=>", 0);
            if (opPlace == -1) {
                int opPlace = condition.find_first_of("==", 0);
            }
        }
        leftCon =  condition.substr(0, opPlace-1);
        rightCon = condition.substr(opPlace+2);
         op = condition.substr(opPlace,2);
    }
    Interpreter* inter = new Interpreter(symbolTable);
    double conExpL = inter->interpret(leftCon)->calculate();
    double conExpR = inter->interpret(rightCon)->calculate();
    if (op == "=="){
        if (conExpL == conExpR){
            return true;
        }
        else {
            return false;
        }    }
    else if (op == "<"){
        if (conExpL < conExpR){
            return true;
        }
        else {
            return false;
        }
    } else if (op == ">"){
        if (conExpL > conExpR){
            return true;
        }
        else {
            return false;
        }
    } else if (op == "=>"){
        if ((conExpL > conExpR)||(conExpL == conExpR)){
            return true;
        }
        else {
            return false;
        }
    } else if (op == "<="){
        if ((conExpL < conExpR)||(conExpL == conExpR)){
            return true;
        }
        else {
            return false;
        }
    } else{ throw "Erorr condition";};
}
