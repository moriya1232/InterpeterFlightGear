//
// Created by yanivmadmon on 12/19/19.
//

#ifndef PROJECTFLY_VAR_H
#define PROJECTFLY_VAR_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include "Command.h"

using namespace std;


class Var : public Command {
    string value ; // the value
    string sim; // the address in the simulator
    char dir ;  // direction
public:
    Var(string val , string si) { this->value = val; this->sim = si;};
    Var(string simu) {this->sim=simu;};
    Var(){};
    void setValue(string s){this->value = s;};
    string getValue(){return this->value;};
    void setSim(string s){this->sim = s;};
    void setDir(string s);
    string doInter(string str,unordered_map <string,Var*>* symbolTable);
    int execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>* queueMas,unordered_map <string,Var*>* symbolTable);
    virtual ~Var(){};

};


#endif //PROJECTFLY_VAR_H
