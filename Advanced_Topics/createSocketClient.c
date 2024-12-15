/******************************************************************************************************
 * @topic: Network Programming in C - Client Implementation
 * @description: This program implements a simple client that connects to a server using sockets in C.
 * The client establishes a connection to the server, sends a message, and waits for a response. 
 * It demonstrates the basics of client-server communication using the TCP protocol.
 * 
 * 
 * Key components:
 * socketCreate()       ==> Creates a socket for TCP communication.
 * socketConnect()      ==> Connects the socket to the server at a specified IP and port.
 * socketSend()         ==> Sends a message from the client to the server.
 * socketReceive()      ==> Receives a response message from the server.
 * main()               ==> Handles the overall client operations, including user input, message sending, 
 *                          and response handling.
 * 
 * Features:
 * - Cross-platform compatibility with conditional compilation for Windows and Linux.
 * - Implements timeout settings for both sending and receiving operations using `setsockopt`.
 * - Handles user input for dynamic message sending to the server.
 * - Processes and displays server responses.
 * 
 * Highlights:
 * - Demonstrates essential steps for establishing a TCP client-server connection.
 * - Includes timeout configuration for enhanced error handling.
 * - Modular design facilitates easier debugging and extension of the client logic.
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
typedef unsigned char UC;

US socketCreate(void) {
    US hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(hSocket == -1){
        perror("Socket creation failed");
    }
    return hSocket;
}

UI socketConnect(UI hSocket) {
    UI iRetval = -1;
    UI serverPort = 12345;

    struct sockaddr_in remote = {0};

    remote.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote.sin_family = AF_INET;
    remote.sin_port = htons(serverPort);

    iRetval = connect(hSocket, (struct sockaddr *)&remote, sizeof(remote));
    if(iRetval < 0)
    perror("Bind Failed");

    return iRetval;
}

/**
 * Send the data to the server and set the timeout of 20 seconds
 */
UI socketSend(UI hSocket, UC * reqst, US reqstLen) {
    UI shortRetval = -1;
    
    struct timeval tv;
    tv.tv_sec = 20;  // 20 sec timeout
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (UC *)&tv,sizeof(tv)) < 0 ){
        printf("Time Out!\n");
        return -1;
    }

    shortRetval = send(hSocket, reqst, reqstLen, 0);

    return shortRetval;
}

/**
 * Receive data from the server 
 */
UI socketReceive(UI hSocket, UC * rsp, UC rcvSize) {
    UI shortRetval = -1;

    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (UC *)&tv,sizeof(tv)) < 0 ){
        printf("Time Out!\n");
        return -1;
    }

    shortRetval = recv(hSocket, rsp, rcvSize, 0);
    printf("Response %s\n",rsp);

    return shortRetval;
}

UI main(UI argc, UC *argv[]) {

    #ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "Winsock initialization failed\n");
        return -1;
    }
    #endif

    UI hSocket = 0, read_size = 0;

    struct sockaddr_in server;
    UC sendToServer[100] = {0};
    UC serverReplay[200] = {0};

    //create socket
    hSocket = socketCreate();
    if (hSocket == -1){
        perror("Socket creation failed");
        return 1;
    }
    printf("Socket Created\n");

    //Connect to remote server
    if (socketConnect(hSocket) < 0) {
        perror("Connect Failed");
        return 1;
    }
    printf("Successfully Connected with Server...\n");

    printf("Enter the message : ");
    fgets(sendToServer, 100, stdin);
    sendToServer[strcspn(sendToServer, "\n")] = '\0';

    // Send data to Server
    socketSend(hSocket, sendToServer, strlen(sendToServer));

    // Receive data from Server
    socketReceive(hSocket, serverReplay, sizeof(serverReplay));
    printf("Server response : %s\n\n", serverReplay);

    closeSocket(hSocket);

    #ifdef _WIN32
    WSACleanup();
    #endif

    return 0;

}
