#include<iostream>
#include<string>

#include<sys/socket.h> 
#include<sys/types.h>

#include<netinet/in.h> 
#include<unistd.h>

using namespace std;

int main() {

    // Create server socket
    int server_socket;
    server_socket = socket(AF_INET,SOCK_STREAM, 0);

    // define server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET; 
	server_address.sin_port = htons(8080);
	server_address.sin_addr.s_addr = INADDR_ANY; 

    // bind socket to specified IP and port
    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    //listen for connections
    listen(server_socket, 1);

    // store the client socket when we listen and then accept the connection
    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    // Receive data from Client
	char client_message[256];
    read(client_socket, &client_message, sizeof(client_message));
	printf("Client message - %s\n ", client_message);

    // send public key
    send(client_socket, "Public key =\n", 15,0);
    cout<<"Public key shared with client\n\n";

    // read the envelope from client
    char buffer[256];
    auto n = read(client_socket, buffer,255);
    if (n < 0) 
        printf("ERROR reading from socket");
    printf("Digital envelope by client : %s\n",buffer);

    // decrypt message Symmetric key and display
    char message[255];
	read(client_socket, &message, sizeof(message));
	cout<<"Client message = "<<message<<"\n";

    // receive the encrypted message from client

    //close socket
    close(server_socket);

    return 0;
}
