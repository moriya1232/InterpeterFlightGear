//
// Created by yanivmadmon on 12/23/19.
//

#ifndef PROJECTFLY_IFCOMMAND_H
#define PROJECTFLY_IFCOMMAND_H


#include "ConditionParser.h"
#include "Var.h"

class IfCommand : public ConditionParser {
    bool condition;
    unordered_map <string,Var*>* symbolTable;

public:
    IfCommand(unordered_map <string,Var*>* symboltable){this->symbolTable = symboltable;}
    int execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>* queueMas,unordered_map <string,Var*>* symbolTable);
    bool conditionBool (string condition);
    virtual ~IfCommand(){};

};


#endif //PROJECTFLY_IFCOMMAND_H
