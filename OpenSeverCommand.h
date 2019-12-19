//
// Created by yanivmadmon on 12/19/19.
//

#ifndef PROJECTFLY_OPENSEVERCOMAND_H
#define PROJECTFLY_OPENSEVERCOMAND_H


#include "Command.h"

class OpenSeverCommand : public Command {
public:
    int excecute(unordered_map <string,Command>* mapCommand,vector<string> data , int index);
    virtual ~OpenSeverCommand(){};
};


#endif //PROJECTFLY_OPENSEVERCOMAND_H
