/*
Class to Encrypt-Decrypt the key using RSA
*/
#include <iostream>
#include <math.h>
#include "rsa_keys.h"

class rsa {

    assymetric_keys __keys;
    vector<double> public_key ;
    vector<double> private_key ;

    public:

        // generating public and private keys 
        // for asymmetric encryption-decryption of symmetric key
        rsa () {
            assymetric_keys __keys;
            public_key = __keys.generate_keys();
            private_key = __keys.get_private_key();
        }

        double encrypt(double sym_key) {

            double c = pow(sym_key, public_key[1]);
            c = fmod(c, public_key[0]);
            return c;
        }

        double decrypt(double cipher)
        {          
            double m = pow(cipher, private_key[1]);
            m = fmod(m, private_key[0]);
            return m;
        }

        ~rsa() {};
};