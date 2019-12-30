//
// Created by yanivmadmon on 12/19/19.
//

#include "Var.h"
int Var :: execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>*queueMas) {
    if (this->dir == 'R') {
        string str = this->sim.substr(1, (str.length() - 1));
        str="set" + str +" "+ this->value+"\r\n";
        queueMas->push(str);
    }
}

void Var::setDir(string s) {if (s == "->"){this->dir = 'R';}else{this->dir = 'L';}};