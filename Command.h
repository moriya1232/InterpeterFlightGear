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
#include <queue>
class Var;
using namespace std;

class Command { // abstract class
public:
    virtual int execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>* queueMas,unordered_map <string,Var*>* symbolTable) = 0;
    virtual ~Command() {}
};


#endif //PROJECTFLY_COMMAND_H
