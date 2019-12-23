//
// Created by yanivmadmon on 12/21/19.
//

#ifndef PROJECTFLY_PRINT_H
#define PROJECTFLY_PRINT_H


#include "Command.h"

class Print :public Command{
public:
    int execute(unordered_map <string,Command*>* mapCommand, vector<string>& data , int index);
    virtual ~Print(){};

};


#endif //PROJECTFLY_PRINT_H
