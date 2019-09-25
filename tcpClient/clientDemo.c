//
// Created by Mário Marques  on 25/09/2019.
//
#include "tcpClient.h"

/***
 * Function to be modified for each different application
 * @param socket
 */
void clientProcess(int socket) {
    int strLen = 255;
    char strToSend[strLen];

    while (1) {
        printf("\n---> Enter string to send: ");
        scanf("%s", strToSend);
        socketWrite(socket, strToSend);

        messageWithSize messageToReceive=receiveMessage(socket);
        if( messageToReceive.lenght == 0) { break; }

        printf("Received from server: %s", messageToReceive.message);
    }
}



int main(int argc,char* argv[]){
    if(argc!=3){
        printf("Usage: IP PORT\n");
        return 0;
    }
    char* ipAddress=argv[0];
    int port=atoi(argv[1]);

    int clientSocket=clientConnect(ipAddress, port);
    clientProcess(clientSocket);
    close(clientSocket);
    printf("Disconnected from server.\n");
    return 0;
}

