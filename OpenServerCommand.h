//
// Created by yanivmadmon on 12/19/19.
//

#ifndef PROJECTFLY_OPENSEVERCOMAND_H
#define PROJECTFLY_OPENSEVERCOMAND_H


#include "Command.h"
#include "Var.h"

class OpenServerCommand :public Command {
    unordered_map<string,Var*>* symboltableSim; // the symbol table from the simulator
    bool* isConnect; // check if the client connect
public:
    OpenServerCommand (unordered_map <string,Var*>* symbolTableSim , bool *isconnect){this->symboltableSim = symbolTableSim; this->isConnect = isconnect;};
     static void initSymballXml(unordered_map<string,Var*>* symboltableSim);
     static void initXmlArr(string* arr);
    string doInter(string str,unordered_map <string,Var*>* symbolTable);
    int execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>* queueMas,unordered_map <string,Var*>* symbolTable);
    static int openServer(string str,unordered_map<string,Var*>* symboltableSim ,bool* isConnect,int client_socket);
    virtual ~OpenServerCommand(){};
};


#endif //PROJECTFLY_OPENSEVERCOMAND_H
