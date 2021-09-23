#include<iostream>
#include<math.h>

#include<sys/socket.h> 
#include<sys/types.h>

#include<netinet/in.h> 
#include <unistd.h>

#include "encrypt.h"


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

	// receive server public key
	double assym_public_key[2];
	read(network_socket, assym_public_key, 2);
	cout<<"Server sent the public key="<<assym_public_key[0]<<" "<<assym_public_key[0]<<"\n";;

	// create digital envelope using RSA
	int __sym_key = 10;
	double digital_env = pow(__sym_key, assym_public_key[1]);
	cout<<"assym_public_key(n,e)="<<"("<<assym_public_key[0]<<","<<assym_public_key[1]<<")\n";
	cout<<"pow(m,e)="<<digital_env<<"\n";
    digital_env = fmod(digital_env, assym_public_key[0]);
	cout<<"% n ="<<digital_env<<"\n";

	// send the digital evelope to server
	cout<<"size digital env = "<<sizeof(digital_env)<<"\n";
	cout<<"digital env = "<<digital_env<<"\n";
	write(network_socket, &digital_env,sizeof(digital_env));

	// send the symmetric encrypted message to server
	string str_server_message = encrypt(argc, argv);
	char server_message[256];

	for(int i=0;i<str_server_message.length();i++) {
		server_message[i] = str_server_message[i];
	}

	write(network_socket, &server_message,sizeof(server_message));

	// close socket
	close(network_socket);

	return 0;
}
