#include<stdio.h>
#include<stdlib.h>

#include<sys/socket.h> //has APIs to create sockets
#include<sys/types.h>

#include<netinet/in.h> //has structure to store address information
#include <unistd.h> // close()

#define PY_SSIZE_T_CLEAN
#include<Python.h>

int main(int argc, char *argv[]) {
	
	// Encrypt using Julius-Caesar cipher
	int key = 10, __value;
	char cipher[256] = {0};
	for (int i = 0; i < 26; ++i) {
		__value = (i + key) % 26;
		cipher[97+i] = __value; //a-z
		cipher[65+i] = __value; //A-Z
	}

	int j = -1;
	char *cipher_message[100];
	for(int i=1;i<argc;i++) {
		while(argv[i][++j]) {
			cipher_message[i-1][j] = cipher[argv[i][j]];
		}
	}

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
	server_address.sin_port = htons(8000); // remote connection port -> integer port put in right network order
	server_address.sin_addr.s_addr = INADDR_ANY; // actual server address - we connect to any IP on local

	// Connect to Other Side
	// returns integer as to if the connectin was made(0) or not
	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	if (connection_status == -1)
		printf("There was an error making a connection to the remote server\n\n");
	
	// send data to Server
	send(network_socket, cipher, sizeof(cipher), 0);
	
	// print the data
	printf("The server sent the data %s \n\n", server_response);
	
	// close socket
	close(network_socket);

	return 0;
}
