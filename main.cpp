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
string doInter(string str,unordered_map <string,Var*>* symbolTable);
vector<string>  lexer (string str);
void parser(unordered_map <string,Command*>* mapCommand,unordered_map <string,Var*>* symbolTable,unordered_map <string,Var*>* symbolTableSim,vector<string>& data,queue<string>* queueMas , bool& isConnect);
int main(int argc,char* argv[]) {
    bool isConnect = false;
    //create the maps and the queue
    unordered_map <string,Command*>* mapCommand = new unordered_map <string,Command*>();
    unordered_map <string,Var*>* symbolTable = new unordered_map <string,Var*>();
    unordered_map <string,Var*>* symbolTableSim = new unordered_map <string,Var*>();
    queue <string>* masQueue=new queue<string>();

    //install the objects in main the map
    OpenServerCommand* openServerCommand = new OpenServerCommand(symbolTableSim,&isConnect);
    ConnectedCommand* connectedCommand = new ConnectedCommand(&isConnect);
    LoopCommand* whileCommand = new LoopCommand(symbolTable);
    IfCommand* ifCommand = new IfCommand(symbolTable);
    Print* print = new Print();
    Sleep* sleep = new Sleep();

    // insert the keys and the objects
    mapCommand->insert({"openDataServer",openServerCommand});
    mapCommand->insert({"connectControlClient",connectedCommand});
    mapCommand->insert({"while",whileCommand});
    mapCommand->insert({"if",ifCommand});
    mapCommand->insert({"Print",print});
    mapCommand->insert({"Sleep",sleep});

    //the lexer
    vector<string> data = lexer(argv[1]);
    // the parser
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
                if((str.at(found+1)=='"')&&(arr.back()=="Print")) {
                    found++;
                    found = str.find_first_of(" \"(),=\t", found);
                    arr.push_back(str.substr(found,str.length()-found-1));
                    last = str.length();
                    break;
                }
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
            if((found!=-1)&&((arr.back()=="Print"))) {
                int temp2=str.find_first_of('"',found+1);
                if(temp2==-1) {
                    arr.push_back(str.substr(found,str.length()-found));
                    last=str.length();
                    break;
                }
                arr.push_back(str.substr((found+1),(temp2-found)+1));
                break;
            }
            if((found!=-1)&&(str.at(found)=='=')) {
                if((str.at(found-1)=='<')||(str.at(found-1)=='>')) {
                    arr.pop_back();
                    arr.push_back(str.substr(found-1,2));
                    found = str.find_first_of(" (),=\t", found);
                    break;
                }
                else {
                    j = str.length() - found;
                    if(str.at(found+1)==' ') {
                        arr.push_back(str.substr(found + 2, j));
                        found = (str.length()) - 1;
                    }
                    else {
                        arr.push_back(str.substr(found+1,j));
                    }
                }
            }
            if((found!=-1)&&(str.at(found)=='(')) {
                i=str.find_first_of(")");
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
string doInter(string str,unordered_map <string,Var*>* symbolTable){
    Interpreter* inter = new Interpreter(symbolTable);
    Expression* exp =  inter->interpret(str);
    double num = exp->calculate();
    auto finalStr = std::to_string(num);
    return finalStr;
}
void parser(unordered_map <string,Command*>* mapCommand,unordered_map <string,Var*>* symbolTable,unordered_map <string,Var*>* symbolTableSim,vector<string>& data,queue<string>* queueMas , bool& isConnect){
   int index = 0 ;
   while (index <  data.size()){
       if ( data[index] == "var"){ // find the var in the symbolTableSim and put him in the symbolTable
           Var* v;
           index++;
           string key = data[index];
           string sim = data[index+3].substr(1,data[index+3].size()-2);
           auto itr = symbolTableSim->find(sim);
           if(itr != symbolTableSim->end()){
               v = symbolTableSim->find(sim)->second;
               string dir = data[index+1];
               v->setDir(dir);
               index+= 4;
           }
           else{ // when the var isn't in the symbolTableSim
               v = new Var();
               v->setValue(doInter(data[index+1],symbolTable));
               index+=2;
           }
           symbolTable->insert({key,v});
       }
      else {
           auto itr = mapCommand->find(data[index]); // look for value in the mapcommand
           if (itr != mapCommand->end()) {
               Command* c = itr->second;
               index += c->execute(mapCommand,data, index,queueMas,symbolTable);
               while (!isConnect){

               }
           }
           else {
               auto itr = symbolTable->find(data[index]); // look for value in the symbolTable
               if (itr != symbolTable->end()) {
                   Var* c = itr->second;
                   index += c->execute(mapCommand, data, index,queueMas,symbolTable);
               }
           }
       }
   }
}