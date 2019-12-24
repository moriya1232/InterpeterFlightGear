//
// Created by yanivmadmon on 12/19/19.
//

#ifndef PROJECTFLY_OPENSEVERCOMAND_H
#define PROJECTFLY_OPENSEVERCOMAND_H


#include "Command.h"
#include "Var.h"

class OpenServerCommand :public Command {
    unordered_map<string,Var*> symboltableSim;
public:
    unordered_map<string,Var *> initSymballXml();
    string* initXmlArr();
    OpenServerCommand (unordered_map <string,Var*>* symbolTableSim){this->symboltableSim = *symbolTableSim;};
    int execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index);
    int openServer(string str);
    OpenServerCommand(unordered_map <string,Var*> mapSym) {
       this->symboltableSim=mapSym;
    }
    virtual ~OpenServerCommand(){};
};


#endif //PROJECTFLY_OPENSEVERCOMAND_H
