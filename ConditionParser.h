//
// Created by yanivmadmon on 12/23/19.
//

#ifndef PROJECTFLY_CONDITIONPARSER_H
#define PROJECTFLY_CONDITIONPARSER_H


#include "Command.h"

class ConditionParser : public Command { //abstract class
public:
    int execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>* queueMas,unordered_map <string,Var*>* symbolTable)=0;
    virtual ~ConditionParser(){};

};


#endif //PROJECTFLY_CONDITIONPARSER_H
