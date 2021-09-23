/*
Decrypts the message argunment and returns the plain text
*/
#include <iostream>
#include <string.h>
using namespace std;
string decrypt(string message, int key)
{
    string result = "";
    int s = 26 - key; // using cyclic property of Caesar-cipher
    // traverse text
    for (int i=0;i<message.length();i++)
    {
        // apply transformation to each character
        if(message[i]==' ' || message[i]=='.') {
            result += message[i];
        }
        // Encrypt Uppercase letters
        else if (isupper(message[i]))
            result += char(int(message[i]+s-65)%26 +65);
 
        // Encrypt Lowercase letters
        else
            result += char(int(message[i]+s-97)%26 +97);
    }
 
    // Return the resulting string
    return result;
}