//
// Created by Mário Marques  on 25/09/2019.
//

#ifndef TCPCLIENTSERVER_TCP_CLIENT_CREATION_H
#define TCPCLIENTSERVER_TCP_CLIENT_CREATION_H

#endif //TCPCLIENTSERVER_TCP_CLIENT_CREATION_H

#include "../includes.h"

/***
 * Connects a TCP client to a TCP server
 * @param ipAddress
 * @param port
 * @return
 */

int clientConnect(char* ipAddress, int port){
    int clientSocket=createSocket();
   struct sockaddr_in sockaddrIn= returnSockAddrIn(ipAddress,port);
    int res = connect(clientSocket, (struct sockaddr *) &sockaddrIn, sizeof(sockaddrIn));
    if(res==-1)
        error("Error connecting to server...\n");
    return clientSocket;
}