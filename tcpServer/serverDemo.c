//
// Created by Mário Marques  on 25/09/2019.
//

#include "tcpServer.h"


/***
 * Processes received message, function has to be modified for each application
 * @param clientSocket socket
 */

void serverProcess(int clientSocket) {
    while (1) {
        messageWithSize receivedMessage=receiveMessage(clientSocket);

        if (checkCtrC(receivedMessage)) { break; }

        int p;
        for (p = 0; receivedMessage.message[p] != '\0'; p++) {
            receivedMessage.message[p] = toupper(receivedMessage.message[p]);
        }

        socketWrite(clientSocket, receivedMessage.message);
        fflush(stdout);
    }

    close(clientSocket);
}
/***
 * Receives and process messages
 * @param serverSocket
 */
void serverLoop(int serverSocket){
        serverProcess(serverSocket);
        printf("Disconnected to client\n");
    }


    /***
     *
     *
     */
int main(int argc,char* argv[]){
    if(argc!=3){
        printf("Usage: IP PORT\n");
        return 0;
    }
    char* ipAddress=argv[0];
    int port=atoi(argv[1]);

   int serverSocket=startTCPServer(ipAddress,port);

   serverLoop(serverSocket);
   close(serverSocket);
    return 0;


}