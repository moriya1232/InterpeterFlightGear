//
// Created by yanivmadmon on 12/19/19.
//

#include "Var.h"
int Var :: execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>*queueMas){
    if (data[index] == "var"){

        Var* v = new Var() ;

    }
    else{

    }
}

void Var::setDir(string s) {if (s == "->"){this->dir = 'R';}else{this->dir = 'L';}};