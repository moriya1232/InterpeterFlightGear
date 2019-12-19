//
// Created by yanivmadmon on 12/19/19.
//

#ifndef PROJECTFLY_OPENSEVERCOMAND_H
#define PROJECTFLY_OPENSEVERCOMAND_H


#include "Command.h"

class OpenSeverComand : public Command {
public:
    int excecute(unordered_map<string, Command>);
    virtual ~OpenSeverComand(){};
};


#endif //PROJECTFLY_OPENSEVERCOMAND_H
