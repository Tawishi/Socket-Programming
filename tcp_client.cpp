#include<stdio.h>
#include<stdlib.h>

#include<sys/socket.h> //has APIs to create sockets
#include<sys/types.h>

#include<netinet/in.h> //has structure to store address information
#include <unistd.h> // close()
#include "encrypt.h" // header to encrypt message

int main(int argc, char** argv) {
	
	// TCP Client

	// Create a Socket
	int network_socket; // socket descriptor

	// AF_INET = domain of socket
	// soc = type of socket; TCP socket (other is UDP socket)
	// third is Protocol : 0=default=TCP(other is raw socket)
	network_socket = socket(AF_INET,SOCK_STREAM, 0);

	// Structure for connection address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET; // type/family of connection address
	server_address.sin_port = htons(8080); // remote connection port -> integer port put in right network order
	server_address.sin_addr.s_addr = INADDR_ANY; // actual server address - we connect to any IP on local

	// Connect to Other Side
	// returns integer as to if the connectin was made(0) or not
	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	if (connection_status == -1)
		printf("There was an error making a connection to the remote server\n\n");
	
	// Receive data from Server
	// char server_response[256];
	// recv(network_socket, &server_response, sizeof(server_response), 0);

	// print the data
	// printf("The server sent the data %s \n\n", server_response);

	// Send encrypted message to Server
	char server_message[256] = "tawishi";
	string str_ server_message = encrypt(argc, argv);
	send(network_socket, server_message, sizeof(server_message), 0);
	
	// close socket
	close(network_socket);

	return 0;
}
