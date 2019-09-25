//
// Created by Mário Marques  on 25/09/2019.
//

#ifndef TCPCLIENTSERVER_INCLUDES_H
#define TCPCLIENTSERVER_INCLUDES_H

#endif //TCPCLIENTSERVER_INCLUDES_H

#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>

/***
 * Message received on a socket
 * lenght; message lenght
 * message: message itself
 */
typedef struct {
    int lenght;
    char message[255];
}messageWithSize;

/***
 * Receives message on socket
 * @param socket socket
 * @return message with respective size
 */
messageWithSize receiveMessage(int socket){
    messageWithSize messageToReceive;
    messageToReceive.lenght = recv(socket, messageToReceive.message, 255, 0);

    printf("Received: \"%s\", Lenght: %d\n", messageToReceive.message, messageToReceive.lenght);
    return messageToReceive;
}

/***
 * Writes an error message to the console and exits the program
 * @param errorMessage Error message to Print
 */
void error(char* errorMessage){
    perror(errorMessage);
    exit(1);
}

/***
 * Check if Ctrl+C has been pressed,
 * @param receivedMessage
 * @return 1 if Ctrl+C is pressed, 0 otherwise
 */
int checkCtrC(messageWithSize receivedMessage){
    if (receivedMessage.lenght == 2 && receivedMessage.message[0] == '#')
        return 1;
    return 0;
}

/***
 * Writes Message to a Socket
 * @param socketToWrite Socket to write
 * @param message Message to write
 */
void socketWrite(int socketToWrite, char* message) {
    long pos = 0;
    while (pos < strlen(message) + 1) {
        pos += write(socketToWrite, message + pos, strlen(message) + 1 - pos);
    }
}

/***
 * Creates TCP socket
 * @return Created Socket
 */
int createSocket(){
    int socketCreation=socket(PF_INET,SOCK_STREAM,0);
    if(-1==socketCreation)
        error("Error creating socket...\n");
    printf("Socket created!\n");
    return socketCreation;
}

/***
 * Creates sockaddr_in structure, to be used by the client and the server
 * @param ipAddress IP address to be used, Eg: 127.0.0.1
 * @param port Port to be used, Eg. 80
 * @return Structure
 */
struct sockaddr_in returnSockAddrIn(char* ipAddress, int port){
    struct sockaddr_in servAddress = {0};
    servAddress.sin_family = AF_INET;
    servAddress.sin_port = htons(port);
    inet_aton(ipAddress, &servAddress.sin_addr);
    return servAddress;
}