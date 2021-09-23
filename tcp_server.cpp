#include<iostream>
#include<vector>
#include <math.h>

#include<sys/socket.h> 
#include<sys/types.h>

#include<netinet/in.h> 
#include<unistd.h>

#include "decrypt.h"
#include "rsa_keys.h"


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
	printf("Client message - %s", client_message);

    // generate the Server Private and Public keys
    assymetric_keys __keys;
    vector<double> public_key = __keys.generate_keys();
    vector<double> private_key = __keys.get_private_key();

    // send public key to client
    double pub_key[] = {public_key[0],public_key[1]};
    send(client_socket, pub_key,sizeof(pub_key),0);
    cout<<"Public key shared with client\n\n";

    // receive digital envelope from client
    double digital_env;
    auto n = read(client_socket, &digital_env,sizeof(digital_env));
    if (n < 0) 
        printf("ERROR reading from socket");

    // decrypt Symmetric key using sender Private key - RSA
    double K = pow(digital_env, private_key[1]);
    K = fmod(K, private_key[0]);
	
    // receive and decrtypt the encrypted message from client
    char message[255];
    auto m = read(client_socket, &message, sizeof(message));
    if (m < 0) 
        printf("ERROR reading from socket");
	cout<<"Encrypted Client message = "<<message<<"\n";

    string plaintext = decrypt(message, K);
	printf("The client sent the message - %s\nwhich translates to ", message);
    cout<<plaintext<<"\n";

    //close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}
