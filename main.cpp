#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <thread>
#include <queue>
#include "Command.h"
#include "OpenServerCommand.h"
#include "ConnectedCommand.h"
#include "Var.h"
#include "Print.h"
#include "Sleep.h"
#include "ex1.h"
#include "LoopCommand.h"
#include "IfCommand.h"


using namespace std;

vector<string>  lexer (string str);
void parser(unordered_map <string,Command*>* mapCommand,unordered_map <string,Var*>* symbolTable,unordered_map <string,Var*>* symbolTableSim,vector<string>& data,queue<string>* queueMas , bool& isConnect);
int main(int argc,char* argv[]) {
    bool isConnect = false;
    unordered_map <string,Command*>* mapCommand = new unordered_map <string,Command*>();
    unordered_map <string,Var*>* symbolTable = new unordered_map <string,Var*>();
    unordered_map <string,Var*>* symbolTableSim = new unordered_map <string,Var*>();
    queue <string>* masQueue=new queue<string>();

    OpenServerCommand* openServerCommand = new OpenServerCommand(symbolTableSim,&isConnect);
    ConnectedCommand* connectedCommand = new ConnectedCommand(&isConnect);
    LoopCommand* whileCommand = new LoopCommand(symbolTable);
    IfCommand* ifCommand = new IfCommand(symbolTable);
    Print* print = new Print();
    Sleep* sleep = new Sleep();

    mapCommand->insert({"openDataServer",openServerCommand});
    mapCommand->insert({"connectControlClient",connectedCommand});
    mapCommand->insert({"while",whileCommand});
    mapCommand->insert({"if",ifCommand});
    mapCommand->insert({"Print",print});
    mapCommand->insert({"Sleep",sleep});

    vector<string> data = lexer(argv[1]);
    parser(mapCommand,symbolTable,symbolTableSim, data,masQueue, isConnect);
    return 0;
}
 vector<string> lexer (string filename) {
    ifstream fp;
    string str;
    vector<string> arr;
    fp.open(filename);
    if (fp.fail()) {
        throw("file not open");
    }
    while(getline(fp,str)) {
        int found = 0;
        int last = 0;
        int i=0;
        int j=0;
        string temp;

        found = str.find_first_of(" (),=\t", found);

        while (found >= 0){
            temp = str.substr(last, found - last);
            if (found != last) {
                arr.push_back(temp);
            }
            if((found!=-1)&&((arr.back()=="while")||(arr.back()=="if"))) {
                int temp1=found+1;
                found=str.find_first_of("{");
                arr.push_back(str.substr(temp1,found-temp1));
                arr.push_back("{");
                found=-1;
                last=(str.length());
                break;
            }
            if((found!=-1)&&(str.at(found)=='=')) {
                if((str.at(found-1)=='<')||(str.at(found-1)=='>')) {
                    arr.pop_back();
                    arr.push_back(str.substr(found-1,2));
                    found = str.find_first_of(" (),=\t", found);
                }
                else {
                    j = str.length() - found;
                    arr.push_back(str.substr(found + 2, j));
                    found = (str.length()) - 1;
                }
            }
            if((found!=-1)&&(str.at(found)=='(')) {
                i=str.find_first_of(")");
                /*if((found<str.length())&&((str.at(found+1)=='/')||(str.at(found+1)=='*')
                ||(str.at(found+1)=='+')||(str.at(found+1)=='-'))) {
                    arr.push_back(str.substr(found+1))
                }*/
                i=i-found;
                arr.push_back(str.substr(found+1,i-1));
                found=str.find_first_of(")", found+1);
            }
            last = found + 1;
            found++;
            found = str.find_first_of(" (),=", found);

        }
        if(last!=str.length()) {
            arr.push_back(str.substr(last,str.length()));
        }
    }
    fp.close();
    return arr;
}
void parser(unordered_map <string,Command*>* mapCommand,unordered_map <string,Var*>* symbolTable,unordered_map <string,Var*>* symbolTableSim,vector<string>& data,queue<string>* queueMas , bool& isConnect){
   int index = 0 ;
   while (index <  data.size()){
       if ( data[index] == "var"){
           index++;
           string key = data[index];
           string dir = data[index+1];
           string sim = data[index+3].substr(1,data[index+3].size()-2);
           Var* v = symbolTableSim->find(sim)->second;
           v->setDir(dir);
           symbolTable->insert({key,v});
           index+= 4;
       }
      else {
           auto itr = mapCommand->find(data[index]);//
           if (itr != mapCommand->end()) {
               Command* c = itr->second;
               index += c->execute(mapCommand,data, index,queueMas);
             //  std::cout << "eeeee" << std::endl;
               while (!isConnect){

               }
           }
           else {
               auto itr = symbolTable->find(data[index]);
               if (itr != symbolTable->end()) {
                   Var* c = itr->second;
                   index += c->execute(mapCommand, data, index,queueMas);
               }
           }
       }
   }
}