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
    string value ;
    string sim;
    char dir ;  // direction
public:
    Var(string val , string si) { this->value = val; this->sim = si;};
    Var(string simu) {this->sim=simu;};
    Var(){};
    void setValue(string s){this->value = s;};
    string getValue(){return this->value;};
    void setSim(const string& s){this->sim = s;};
    void setDir(const string& s){if (s == "->"){this->dir = 'R';}else{this->dir = 'L';}};
    int execute(unordered_map <string,Command*>* mapCommand, vector<string>& data , int index);
    virtual ~Var(){};

};


#endif //PROJECTFLY_VAR_H
