//
// Created by yanivmadmon on 12/19/19.
//

#ifndef PROJECTFLY_COMMAND_H
#define PROJECTFLY_COMMAND_H
#include "main.cpp"
using namespace std;

class Command {
public:
    virtual int excecute(vector<string> data , int index) = 0;
    virtual ~Command(){};
};


#endif //PROJECTFLY_COMMAND_H
