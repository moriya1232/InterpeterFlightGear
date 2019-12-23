//
// Created by yanivmadmon on 12/19/19.
//

#ifndef PROJECTFLY_OPENSEVERCOMAND_H
#define PROJECTFLY_OPENSEVERCOMAND_H


#include "Command.h"
#include "Var.h"

class OpenServerCommand :public Command {
    unordered_map <string,Var*>* symboltableSim;
public:
    OpenServerCommand (unordered_map <string,Var*>* symbolTableSim){this->symboltableSim =symbolTableSim;};
    int execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index);
    virtual ~OpenServerCommand(){};
};


#endif //PROJECTFLY_OPENSEVERCOMAND_H
