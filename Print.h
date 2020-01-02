//
// Created by yanivmadmon on 12/21/19.
//

#ifndef PROJECTFLY_PRINT_H
#define PROJECTFLY_PRINT_H


#include "Command.h"

class Print :public Command{
public:
    int execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>* queueMas,unordered_map <string,Var*>* symbolTable);
    string doInter(string str,unordered_map <string,Var*>* symbolTable);
        virtual ~Print(){};

};


#endif //PROJECTFLY_PRINT_H
