#include<iostream>

#include<sys/socket.h> 
#include<sys/types.h>

#include<netinet/in.h> 
#include <unistd.h> 


using namespace std;

int main(int argc, char** argv) {
	
	// TCP Client

	// Create a Socket
	int network_socket;
	network_socket = socket(AF_INET,SOCK_STREAM, 0);

	// Structure for connection address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(8080);
	server_address.sin_addr.s_addr = INADDR_ANY; 

	// Connect to Other Side
	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	if (connection_status == -1)
		printf("There was an error making a connection to the remote server\n\n");

	// request public key
	write(network_socket, "Please share the server Public key\n",sizeof("Please share the server Public key\n"));

	// // Send encrypted message to Server
	// string str_server_message = encrypt(argc, argv);
	// char server_message[256];

	// for(int i=0;i<str_server_message.length();i++) {
	// 	server_message[i] = str_server_message[i];
	// }

	// receive server public key
	char message[255];
	read(network_socket, &message, sizeof(message));
	cout<<"Server sent the public key = \t"<<message<<"\n";

	// send the digital evelope to server
	write(network_socket, "Digital Envelope\n",sizeof("Digital Envelope\n"));

	// send the symmetric encrypted message to server

	// close socket
	close(network_socket);

	return 0;
}
