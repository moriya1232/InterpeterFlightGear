//
// Created by yanivmadmon on 12/19/19.
//

#ifndef PROJECTFLY_CONNECTEDCOMMAND_H
#define PROJECTFLY_CONNECTEDCOMMAND_H
#include "main.cpp"


class ConnectedCommand: public Command {
public:
    int excecute(vector<string> data , int index);
    virtual ~ConnectedCommand(){};

};


#endif //PROJECTFLY_CONNECTEDCOMMAND_H
