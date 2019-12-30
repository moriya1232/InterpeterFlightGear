//
// Created by yanivmadmon on 12/21/19.
//

#include "Sleep.h"
#include <unistd.h>
#include <thread>


int Sleep:: execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>* queueMas){

    string s = data[index+1];
    int time = stoi(s);
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    return 2;

}
