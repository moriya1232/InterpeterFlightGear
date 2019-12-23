//
// Created by yanivmadmon on 12/19/19.
//

#ifndef PROJECTFLY_COMMAND_H
#define PROJECTFLY_COMMAND_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
using namespace std;

class Command {
public:
    virtual int execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index) = 0;
    virtual ~Command() {}
};


#endif //PROJECTFLY_COMMAND_H
