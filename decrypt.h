#include <iostream>
#include <string.h>
using namespace std;
string decrypt(string message)
{
    string result = "";
    int s = 26 - 10;
    // traverse text
    for (int i=0;i<message.length();i++)
    {
        // apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(message[i]))
            result += char(int(message[i]+s-65)%26 +65);
 
    // Encrypt Lowercase letters
    else
        result += char(int(message[i]+s-97)%26 +97);
    }
 
    // Return the resulting string
    return result;
}