#include<stdio.h>
#include<stdlib.h>

#include<sys/socket.h> //has APIs to create sockets
#include<sys/types.h>

#include<netinet/in.h> //has structure to store address information
#include <unistd.h> // close()

int main() {

    char server_message[256] = "You have reached the server";

    // Create server socket
    int server_socket;
    server_socket = socket(AF_INET,SOCK_STREAM, 0);

    // define server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET; // type/family of connection address
	server_address.sin_port = htons(8080); // remote connection port -> integer port put in right network order
	server_address.sin_addr.s_addr = INADDR_ANY; // actual server address - we connect to any IP on local

    // bind socket to specified IP and port
    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    //listen for connections
    // 1 arg - server socket
    // 2 arg - backlog: how many connections can be waiting for the socket
    listen(server_socket, 1);

    // store the client socket when we listen and then accept the connection
    int client_socket;
    // 1-socket for server
    // 2-structure for address for client
    // 3-size for address of client
    client_socket = accept(server_socket, NULL, NULL);

    // send data to client
    // 1-client socket
    // 2-data, 3- size of data
    send(client_socket, server_message, sizeof(server_message), 0);

    //close socket
    close(server_socket);

    return 0;
}
