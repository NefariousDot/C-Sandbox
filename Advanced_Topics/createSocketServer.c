/******************************************************************************************************
 * @topic: Network Programming in C - Server Implementation
 * @description: This program demonstrates the implementation of a simple server using sockets in C.
 * The server listens for incoming client connections, accepts them, and facilitates basic message exchange.
 * It demonstrates the use of socket creation, binding, listening, and accepting connections for TCP communication.
 * 
 * 
 * Key components:
 * socketCreate()       ==> Creates a socket using the `socket` system call.
 * bindCreatedSocket()  ==> Binds the socket to a local port and IP address for listening.
 * main()               ==> Manages the lifecycle of the server: listens for incoming connections, 
 *                          receives client messages, and sends responses based on predefined logic.
 * 
 * Features:
 * - Cross-platform compatibility with conditional compilation for Windows and Linux.
 * - Implements robust error handling for socket creation, binding, and client connection acceptance.
 * - Handles incoming client messages and responds appropriately based on message content.
 * - Demonstrates socket-level communication, including send and receive operations.
 * - Uses blocking sockets for synchronous communication.
 * 
 * Highlights:
 * - Modularized functions for socket creation and binding enhance code readability and reuse.
 * - Compatible with both Windows (using Winsock) and Linux environments.
 * - Provides a simple yet effective framework to understand server-side socket programming.
 ******************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <winsock2.h>
#include <winsock2.h>
#include <windows.h>
#define closeSocket(s) closesocket(s)
#define sleep(x) Sleep(1000 * x)
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define closeSocket(s) close(s)
#endif

typedef unsigned int UI;
typedef unsigned short US;
typedef unsigned long UL;

UI socketCreate(void){
    US hSocket;
    printf("Creating the Socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(hSocket == -1){
        perror("Socket creation failed");
    }
    return hSocket;
}

UI bindCreatedSocket(UI hSocket){
    UI iRetval = -1;
    UI clientPort = 12345;

    struct sockaddr_in remote = {0};

    //Internet addr family 
    remote.sin_family = AF_INET;

    //Any incoming interface
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(clientPort); // Local Port 

    iRetval = bind(hSocket, (struct sockaddr *)&remote, sizeof(remote));
    if(iRetval < 0)
    perror("Bind Failed");

    return iRetval;
}

int main(int argc, char *argv[]){

    // WSADATA wsaData;
    #ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "Winsock initialization failed\n");
        return -1;
    }
    #endif

    UI socket_desc = 0, sock = 0;

    #ifdef _WIN32
    int clientLen = 0;
    #else
    socklen_t clientLen = 0;
    #endif

    struct sockaddr_in client;
    char client_message[200] = {0};
    char message[100] = {0};
    const char *pMessage = "Hello! From Ram's Server";

    // Initialize Winsock 
    // WSAStartup(MAKEWORD(2, 2), &wsaData);

    

    socket_desc = socketCreate();
    if(socket_desc == -1){
        // printf("Could not create socket\n");
        return -1;
    }

    printf("Socket Created\n");

    //bind
    if(bindCreatedSocket(socket_desc) < 0){
        // perror("Bind failed.");
        return -1;
    }

    printf("Bind Done..\n");

    //Listen
    listen(socket_desc, 3);

    while(1){
        printf("Waiting for incoming connection....\n");
        clientLen = sizeof(struct sockaddr_in);

        //Accept connections form an incoming client
        sock = accept(socket_desc, (struct sockaddr *)&client,&clientLen); //(socklen_t *)&clientLen);

        if(sock < 0){
            perror("accept failed");
            return -1;
        }

        printf("Connection Accepted\n");
        memset(client_message, '\0', sizeof(client_message));
        memset(message, '\0', sizeof(message));

        // If receive a reply from client
        if(recv(sock, client_message, sizeof(client_message), 0) < 0){
            printf("Receive Failed\n");
            closeSocket(sock);
            break;
        }

        printf("Client replay : %s\n", client_message);

        if(strcmp(pMessage, client_message) == 0){
            strncpy(message, "Hi, there !",sizeof(message) - 1);
        }
        else {
            strncpy (message, "Invalid Message", sizeof(message) - 1);
        }

        // send some data
        if(send(sock, message, strlen(message), 0) < 0){
            printf("send failed\n");
            return 1;
        }

        closeSocket(sock);

        sleep(1);

    }


    // Cleanup Winsock 
    // WSACleanup();

    #ifdef _WIN32
    WSACleanup();
    #endif

    return 0;
}