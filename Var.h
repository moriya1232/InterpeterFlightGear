//
// Created by yanivmadmon on 12/19/19.
//

#ifndef PROJECTFLY_VAR_H
#define PROJECTFLY_VAR_H


#include "Command.h"

class Var : public Command {
    string value ;
    string sim;
public:
    Var(string val , string si) { this->value = val; this->sim = si};
    Var(){};
    int excecute(unordered_map <string,Command>* mapCommand,vector<string> data , int index);
    virtual ~Var(){};

};


#endif //PROJECTFLY_VAR_H
