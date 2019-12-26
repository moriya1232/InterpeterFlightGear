//
// Created by yanivmadmon on 12/19/19.
//

#include "OpenServerCommand.h"
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>


int OpenServerCommand:: execute(unordered_map<string,Command *> * mapCommand, vector<std::__cxx11::string> & data, int index) {
    //initSymballXml();
   return 2;
};
void OpenServerCommand:: initSymballXml(unordered_map<string,Var*>* symboltableSim) {
    unordered_map<string,Var *>* tempMap = symboltableSim;
    tempMap->insert({"/instrumentation/airspeed-indicator/indicated-speed-kt",
                    new Var("instrumentation/airspeed-indicator/indicated-speed-kt")});
    tempMap->insert({"/sim/time/warp",new Var("sim/time/warp")});
    tempMap->insert({"/controls/switches/magnetos",new Var("controls/switches/magnetos")});
    tempMap->insert({"/instrumentation/heading-indicator/offset-deg",
                    new Var("/instrumentation/heading-indicator/offset-deg")});
    tempMap->insert({"/instrumentation/altimeter/indicated-altitude-ft",
                    new Var("instrumentation/altimeter/indicated-altitude-ft")});
    tempMap->insert({"/instrumentation/altimeter/pressure-alt-ft",
                    new Var("instrumentation/altimeter/pressure-alt-ft")});
    tempMap->insert({"/instrumentation/attitude-indicator/indicated-pitch-deg",
                    new Var("instrumentation/attitude-indicator/indicated-pitch-deg")});
    tempMap->insert({"/instrumentation/attitude-indicator/indicated-roll-deg",
                    new Var("instrumentation/attitude-indicator/indicated-roll-deg")});
    tempMap->insert({"/instrumentation/attitude-indicator/internal-pitch-deg",
                    new Var{"instrumentation/attitude-indicator/internal-pitch-deg"}});
    tempMap->insert({"/instrumentation/attitude-indicator/internal-roll-deg",
                    new Var("instrumentation/attitude-indicator/internal-roll-deg")});
    tempMap->insert({"/instrumentation/encoder/indicated-altitude-ft",
                    new Var("/instrumentation/encoder/indicated-altitude-ft")});
    tempMap->insert({"/instrumentation/encoder/pressure-alt-ft",
                    new Var("/instrumentation/encoder/pressure-alt-ft")});
    tempMap->insert({"/instrumentation/gps/indicated-altitude-ft",
                    new Var("/instrumentation/gps/indicated-altitude-ft")});
    tempMap->insert({"/instrumentation/gps/indicated-ground-speed-kt",
                    new Var("/instrumentation/gps/indicated-ground-speed-kt")});
    tempMap->insert({"/instrumentation/gps/indicated-vertical-speed",
                    new Var("/instrumentation/gps/indicated-vertical-speed")});
    tempMap->insert({"/instrumentation/heading-indicator/indicated-heading-deg",
                    new Var("/instrumentation/heading-indicator/indicated-heading-deg")});
    tempMap->insert({"/instrumentation/magnetic-compass/indicated-heading-deg",
                    new Var("/instrumentation/magnetic-compass/indicated-heading-deg")});
    tempMap->insert({"/instrumentation/slip-skid-ball/indicated-slip-skid",
                    new Var("/instrumentation/slip-skid-ball/indicated-slip-skid")});
    tempMap->insert({"/instrumentation/turn-indicator/indicated-turn-rate",
            new Var("/instrumentation/turn-indicator/indicated-turn-rate")});
    tempMap->insert({"/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
                    new Var("/instrumentation/vertical-speed-indicator/indicated-speed-fpm")});
    tempMap->insert({"/controls/flight/aileron",new Var("controls/flight/aileron")});
    tempMap->insert({"/controls/flight/elevator",new Var("controls/flight/elevator")});
    tempMap->insert({"/controls/flight/rudder",new Var("controls/flight/rudder")});
    tempMap->insert({"/controls/flight/flaps",new Var("controls/flight/flaps")});
    tempMap->insert({"/controls/engines/engine/throttle",
                    new Var("/controls/engines/engine/throttle")});
    tempMap->insert({"/controls/engines/current-engine/throttle",
                    new Var("/controls/engines/current-engine/throttle")});
    tempMap->insert({"/controls/switches/master-avionics",
                    new Var("/controls/switches/master-avionics")});
    tempMap->insert({"/controls/switches/starter",new Var("controls/switches/starter")});
    tempMap->insert({"/engines/active-engine/auto-start",
                    new Var("/engines/active-engine/auto-start")});
    tempMap->insert({"/controls/flight/speedbrake",new Var("controls/flight/speedbrake")});
    tempMap->insert({"/sim/model/c172p/brake-parking",
                    new Var("/sim/model/c172p/brake-parking")});
    tempMap->insert({"/controls/engines/engine/primer",
                    new Var("/controls/engines/engine/primer")});
    tempMap->insert({"/controls/engines/current-engine/mixture",
                    new Var("/controls/engines/current-engine/mixture")});
    tempMap->insert({"/controls/switches/master-bat",
                    new Var("/controls/switches/master-bat")});
    tempMap->insert({"/controls/switches/master-alt",
                    new Var("/controls/switches/master-alt")});
    tempMap->insert({"/engines/engine/rpm",new Var("engines/engine/rpm")});
};
vector<string> OpenServerCommand:: initXmlArr() {
        vector<string> arr;
        arr[0] = "/instrumentation/airspeed-indicator/indicated-speed-kt";
        arr[1] = "/sim/time/warp";
        arr[2] = "/controls/switches/magnetos";
        arr[3] = "/instrumentation/heading-indicator/offset-deg";
        arr[4] = "/instrumentation/altimeter/indicated-altitude-ft";
        arr[5] = "/instrumentation/altimeter/pressure-alt-ft";
        arr[6] = "/instrumentation/attitude-indicator/indicated-pitch-deg";
        arr[7] = "/instrumentation/attitude-indicator/indicated-roll-deg";
        arr[8] = "/instrumentation/attitude-indicator/internal-pitch-deg";
        arr[9] = "/instrumentation/attitude-indicator/internal-roll-deg";
        arr[10] = "/instrumentation/encoder/indicated-altitude-ft";
        arr[11] = "/instrumentation/encoder/pressure-alt-ft";
        arr[12] = "/instrumentation/gps/indicated-altitude-ft";
        arr[13] = "/instrumentation/gps/indicated-ground-speed-kt";
        arr[14] = "/instrumentation/gps/indicated-vertical-speed";
        arr[15] = "/instrumentation/heading-indicator/indicated-heading-deg";
        arr[16] = "/instrumentation/magnetic-compass/indicated-heading-deg";
        arr[17] = "/instrumentation/slip-skid-ball/indicated-slip-skid";
        arr[18] = "/instrumentation/turn-indicator/indicated-turn-rate";
        arr[19] = "/instrumentation/vertical-speed-indicator/indicated-speed-fpm";
        arr[20] = "/controls/flight/aileron";
        arr[21] = "/controls/flight/elevator";
        arr[22] = "/controls/flight/rudder";
        arr[23] = "/controls/flight/flaps";
        arr[24] = "/controls/engines/engine/throttle";
        arr[25] = "/controls/engines/current-engine/throttle";
        arr[26] = "/controls/switches/master-avionics";
        arr[27] = "/controls/switches/starter";
        arr[28] = "/engines/active-engine/auto-start";
        arr[29] = "/controls/flight/speedbrake";
        arr[30] = "/sim/model/c172p/brake-parking";
        arr[31] = "/controls/engines/engine/primer";
        arr[32] = "/controls/engines/current-engine/mixture";
        arr[33] = "/controls/switches/master-bat";
        arr[34] = "/controls/switches/master-alt";
        arr[35] = "/engines/engine/rpm";
        return arr;
};
 int OpenServerCommand:: openServer(string str ,unordered_map<string,Var*>* symboltableSim, bool* isConnect) {
     initSymballXml(symboltableSim);
     int port=stoi(str);
    string* arr;
   // arr=initXmlArr();
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }

    //bind socket to IP address
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);

    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        return -2;
    }

    //making socket listen to the port
    if (listen(socketfd, 5) == -1) {
        std::cerr << "Error during listening command" << std::endl;
        return -3;
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }

    // accepting a client
    int client_socket = accept(socketfd, (struct sockaddr *) &address,
                               (socklen_t *) &address);

    if (client_socket == -1) {
        std::cerr << "Error accepting client" << std::endl;
        return -4;
    }

    close(socketfd); //closing the listening socket

    //reading from client
    char buffer[1024] = {0};
    string str1="";
     *isConnect = true;
     while(true) {
        int i = 0;
        int j = 0;
        int valread = read(client_socket, buffer, 1024);
        while (buffer[i] != '\n') {
            while (buffer[i] != ',') {
                str1 += buffer[i];
                i++;
            }
            //float f = stof(str1);
            symboltableSim->at(arr[j])->setValue(str1) ;
            j++;
            i++;
        }
    }
};



