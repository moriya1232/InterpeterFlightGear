//
// Created by yanivmadmon on 12/19/19.
//

#include "ConnectedCommand.h"
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <queue>
#include <thread>
int ConnectedCommand::execute(unordered_map <string,Command*>* mapCommand,vector<string>& data , int index,queue<string>* queueMas) {
    int found =data[index+1].find_first_of(",",0);
    string localhost = data[index+1].substr(1,found-1);
    string port =  data[index+1].substr(found+1);

    int PORT = stoi(port);
    //create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    int n = localhost.length();
    char char_array[n + 1];
    strcpy(char_array, localhost.c_str());

    if (client_socket == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }

    //We need to create a sockaddr obj to hold address of server
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;//IP4
    address.sin_addr.s_addr = inet_addr(char_array);  //the localhost address
    address.sin_port = htons(PORT);
    //we need to convert our number (both port & localhost)
    // to a number that the network understands.

    // Requesting a connection with the server on local host with port 8081
    int is_connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
    if (is_connect == -1) {
        std::cerr << "Could not connect to host server" << std::endl;
        return -2;
    } else {
        std::cout << "Client is now connected to server" << std::endl;
    }

    *this->isConnect = false ;
    thread client(ConnectedCommand::sendMassage,client_socket,queueMas , this->isConnect);
    client.detach();

    //close(client_socket);
}
void ConnectedCommand:: sendMassage(int clientSocket,queue<string>* queueMassage ,bool* isConnect) {
        while (true) {

            if (!queueMassage->empty()) {
                string s = queueMassage->front();
                int n = s.length();
                char char_array[n + 1];
                strcpy(char_array, s.c_str());
                auto mas = char_array;
                int is_sent = send(clientSocket, mas, strlen(mas), 0);
                if (is_sent == -1) {
                    std::cout << "Error sending message" << std::endl;
                } else {
                    std::cout << "message sent to server" << std::endl;
                    queueMassage->pop();
                }
               *isConnect = true;
            }
        }
    }
