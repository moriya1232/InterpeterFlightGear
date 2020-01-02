//
// Created by yanivmadmon on 12/23/19.
//

#ifndef PROJECTFLY_LOOPCOMMAND_H
#define PROJECTFLY_LOOPCOMMAND_H


#include "ConditionParser.h"
#include "Var.h"

class LoopCommand : public ConditionParser {
    bool condition;
    unordered_map <string,Var*>* symbolTable;

public:
    LoopCommand(unordered_map <string,Var*>* symboltable){this->symbolTable = symboltable;}
    int execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>* queueMas,unordered_map <string,Var*>* symbolTable);
    bool conditionBool (string condition);
    virtual ~LoopCommand(){};

};


#endif //PROJECTFLY_LOOPCOMMAND_H
