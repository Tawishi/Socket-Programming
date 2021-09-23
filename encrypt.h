/*
Encrypts the message argunment and returns the cipher text
*/
#include <iostream>
#include <string.h>
using namespace std;
string encrypt(int argc, char** argv) {

	int __value;
	int key = 10;
	char cipher[256] = {};
	for (int i = 0; i < 26; ++i) {
		__value = (i + key) % 26;
		cipher[97+i] = __value + 97; //a-z
		cipher[65+i] = __value + 65; //A-Z
	}
	
	int j = -1;
	int index;
	string cipher_message;
	for(int i=1;i<argc;++i) {
		while(argv[i][++j]) {
			if(argv[i][j]==' ' || argv[i][j]=='.') {
				cipher_message += argv[i][j];
				continue;
			}
			index = int(argv[i][j]);
			cipher_message += cipher[index];
		}
	}
	return cipher_message;
}