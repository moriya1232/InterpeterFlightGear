//
// Created by yanivmadmon on 12/19/19.
//

#ifndef PROJECTFLY_CONNECTEDCOMMAND_H
#define PROJECTFLY_CONNECTEDCOMMAND_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include "Command.h"

using namespace std;




class  ConnectedCommand :public  Command {
    bool* isConnect;
public:
    ConnectedCommand (bool *isconnect){this->isConnect = isconnect;};
    int execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>* queueMas);
    virtual ~ConnectedCommand(){};
    static void sendMassage(int clientSocket,queue<string>* queueMassage ,bool* isConnect);


};


#endif //PROJECTFLY_CONNECTEDCOMMAND_H
