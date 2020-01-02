//
// Created by yanivmadmon on 12/21/19.
//

#ifndef PROJECTFLY_SLEEP_H
#define PROJECTFLY_SLEEP_H


#include "Command.h"

class Sleep : public Command{
public:
    int execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>* queueMas,unordered_map <string,Var*>* symbolTable);
    virtual ~Sleep(){};

};


#endif //PROJECTFLY_SLEEP_H
