#include<iostream>
#include<string.h>
#include "en-decrypt.h"

using namespace std;

// Code to demonstrate RSA algorithm
int main()
{
	rsa _algo;
	double m = _algo.encrypt(12);
	cout<<m<< "\n";
	cout<<_algo.decrypt(m)<<"\n";
	return 0;
}
