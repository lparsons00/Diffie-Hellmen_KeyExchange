#include <cstdlib>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <bits/stdc++.h> 
#include <cmath>

using namespace std;

int secret(int x){
    x = (rand() % 100) + 1;
    return x;
}

int prime(int x){
    //function returning a prime value
    bool prime = false;
    while(prime == false){
        prime = true;
        x = (rand() % 100) + 1;
        for(int i = 2; i < x-1; i++){
            if(x%i == 0){
                prime = false;
                i = i+100;
            }
        }
    }
    return x;
}

bool checkPrime(int x){
    bool prime = true;
    if( x < 2){
        prime = false;
    } else {
        for(int i = 2; i < x-1; i++){
            if(x%i == 0){
                prime = false;
                i = i+10000;
            }
        }
    }
    return prime;
}
bool checkCoPrime(int a, int b){
    bool coPrime = true;
    if( a < 2){
        coPrime = false;
    } else {
        if(__gcd(b, a) != 1){
            coPrime = false;
        }
    }
    return coPrime;
}

int primativeRoot(int a, int b){
    // to check for a prim root we must 
    // check all possible orders of b on a;
    // ensuring b-1 is the smallest integer that a^b-1 = 1 % (b-2)
    bool primative = false;
    while(primative == false){
        primative = true;
        a = (rand() % b) + 1;
        
        for(int i = 2; i < a; i++){
            if(__gcd(b, a) != 1){
                primative = false;
            }
        }
    }
    return a;
}

int main(int argc, char** argv) {
    srand(time(0));
    //secret keys
    int xA, xB;
    //prime and primative root
    int p, q;
    //shared secret keys
    int k, l;
    //public keys
    int A, B;
    //determines whether random input or not
    int inputType;
    //check if values are valid
    bool pPrime, qCoPrime;
    
    cout << "Input 0 for random example\n Input 1 for manual input\n";
    cin >> inputType;
    
    if(inputType == 0){
        //p must be public, prime number
        p = prime(p);
        cout << "p: " << p << endl;
        //xA must be 'secret' and be in the finite field of Zp
        xA = secret(xA);
        cout << "XA: " << xA << endl;
        xB = secret(xB);
        cout << "XB: " << xB << endl;
        
        q = primativeRoot(q, p-1);
        cout << "q: " << q << endl;
    } else {
        //p to be prime
        pPrime = false;
        while(pPrime == false){
            cout << "Input for p:\n";
            cin >> p;
            pPrime = checkPrime(p);
        }
        
        xA = 10000; 
        xB = 10000;
        while(xA > p){
            cout << "Input for xA:\n";
            cin >> xA;
            if(xA < 1){
                xA = 10000;
            }
        }
        while(xB > p){
            cout << "Input for xB:\n";
            cin >> xB;
            if(xB < 1){
                xB = 10000;
            }
        }
       
        //q coprime to p-1
        qCoPrime = false;
        while(qCoPrime == false){
            cout << "Input for q:\n";
            cin >> q;   
            qCoPrime = checkCoPrime(q, p-1);
        }
    }
    cout << "Public Numbers P & Q:\n"
         << "P: " << p << endl
         << "Q: " << q << endl;
         
    cout << "Person A has selected a private key: " << xA << endl;
    cout << "Person B has selected a private key: " << xB << endl;
    
    cout << "Person A & B compute public keys" << endl;
    A = pow(q, xA);
    A = A%p;

    cout << "Person A public key: " << A << endl;
    
    B = pow(q, xB);
    B = B%p;
    cout << "Person B public key: " << B << endl;
    
    cout << "Person A & B compute symmetric keys" << endl;
    k = pow(B, xA);
    k = k%p;
    cout << "Person A symmetric key: " << k << endl;
    l = pow(A, xB);
    l = l%p;
    cout << "Person B symmetric key: " << l << endl;
    return 0;
}

