//
// Created by yanivmadmon on 12/23/19.
//

#include "IfCommand.h"
#include "ex1.h"


int IfCommand:: execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>* queueMas,unordered_map <string,Var*>* symbolTable){

    index++;
    string con = data[index];
    this->condition = conditionBool(con); // check the value of the condition and give true or false
    index+=2;
    int count = index;
    int count1 = 0;
    if (this->condition){
        index -= count1;
        while(data[index] != "}") {
            auto itr = mapCommand->find(data[index]); // checks in the mapcommand
            if (itr != mapCommand->end()) {
                Command *c = itr->second;
                index += c->execute(mapCommand, data, index, queueMas,symbolTable);
            } else {
                auto itr = symbolTable->find(data[index]); // checks in the symbol table
                if (itr != symbolTable->end()) {
                    Var *c = itr->second;
                    index += c->execute(mapCommand, data, index, queueMas, symbolTable);
                }
            }
        }
        this->condition = conditionBool(con);
        count1 = index - count; // the number that the index move up
    }
    if(count==index) {
        while (data[index]!="}") {
            count1++;
        }
        count1++;
        return count1;
    }

    return count1+ 4;}
bool IfCommand::  conditionBool (string condition){
    string leftCon ;
    string rightCon;
    string op;

    int opPlace = condition.find_first_of("=", 0); // check what the operator
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
        leftCon =  condition.substr(0, opPlace-1); // the left side in the condition
        rightCon = condition.substr(opPlace+2); // the right side in the condition
        op = condition.substr(opPlace,2); // the operator
    }
    Interpreter* inter = new Interpreter(symbolTable);
    float conExpL = inter->interpret(leftCon)->calculate(); // if this experssion doing interpetion
    float conExpR = inter->interpret(rightCon)->calculate();
    if (op == "=="){  // checks what the operator
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
