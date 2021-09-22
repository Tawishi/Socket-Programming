#include<iostream>
#include<vector>
using namespace std;

//keys
class assymetric_keys {

    vector<double> __private_key;
    vector<double> __public_key;
    double p,q,n,e,phi,d;
    
    // Returns gcd of a and b
    int gcd(int a, int b)
    {
        int temp;
        while (1)
        {
            temp = a%b;
            if (temp == 0)
                return b;
            a = b;
            b = temp;
        }
    }

    // calculate and store e,d
    void setter(double p=3,double q=7) {

        n = p*q;

        e = 2; // initialize
        phi = (p-1)*(q-1);
        while (e < phi)
        {
            // e must be co-prime to phi and
            // smaller than phi.
            if (gcd(e, phi)==1)
                break;
            else
                e++;
        }

        double k = 2; // random
	    d = (1 + (k*phi))/e;
    }

    public:
        vector<double> generate_keys() {

            setter();
            
            __public_key.push_back(n);
            __public_key.push_back(e);

            __private_key.push_back(n);
            __private_key.push_back(d);

            for(int i=0;i<__public_key.size();i++)
                cout<<__public_key[i]<<" ";
            cout<<endl;

            return __public_key;
        }

        vector<double> get_private_key() {

            for(int i =0;i<__private_key.size();i++)
                cout<<__private_key[i]<<" ";
            cout<<endl;

            return __private_key;
        }
};