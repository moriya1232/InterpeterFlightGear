//
// Created by yanivmadmon on 12/21/19.
//

#include "Print.h"
int Print:: execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>* queueMas){
    cout << data[index+1];
    return 2;
}
