//
// Created by Mário Marques  on 25/09/2019.
//

#ifndef TCPCLIENTSERVER_TCP_SERVER_CREATION_H
#define TCPCLIENTSERVER_TCP_SERVER_CREATION_H

#endif //TCPCLIENTSERVER_TCP_SERVER_CREATION_H

#include "../includes.h"

/***
 * Binds the server to a specific IP address and Port
 * @param serverSocket Socket to be binded
 * @param ipAddress IP adress to bind
 * @param port Port to bind
 * @return New binded serverSocket
 */
int serverBind(int serverSocket, char* ipAddress,int port){
    struct sockaddr_in servAddr = returnSockAddrIn(ipAddress, port);
    int result = bind(serverSocket, (struct sockaddr *) &servAddr, sizeof(servAddr));
    if(-1==result)
        error("Error binding socket...\n");
    printf("Server is binded!\n");
    return serverSocket;
}
/***
 * Listen for a connection
 * @param serverSocket Socket to listen to
 */
void serverListen(int serverSocket){
    listen(serverSocket,5);

}

/***
 * Accepts a connection
 * @param serverSocket Socket to Accept connection
 * @return New socket with accepted connection
 */
int serverAccept(int serverSocket){
    struct sockaddr_in cli_addr;
    socklen_t client_addr_length = sizeof(cli_addr);
   int newSocket = accept(serverSocket, (struct sockaddr *) &cli_addr, &client_addr_length);
   if(-1==newSocket)
       error("Error accepting...\n");
   printf("Connected to client!\n");
    return newSocket;
}

/***
 * Starts a TCP server, binds the server to a specific port and IP address, listens for a connection and accepts it.
 * @param ipAddress
 * @param port
 * @return Socket with accepted connection
 */

int startTCPServer(char* ipAddress, int port){
    int serverSocket=createSocket();
     serverSocket=serverBind(serverSocket,ipAddress,port);
     serverListen(serverSocket);
    return serverAccept(serverSocket);


}
