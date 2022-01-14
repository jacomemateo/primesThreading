#include <iostream>
#include <cmath>
#include <sodium.h>
using std::cout;

 int modulo(int a, int b, int n){
    long long x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n;
        }
        y = (y*y) % n;
        b /= 2;
    }
    return x % n;
}


bool singleTest(int n, int a) {
    int exp = n - 1;
    
    while(!(exp & 1)) {
        exp >>= 1;
    }

    if (modulo(a, exp, n) == 1 ) {
        return true;
    }
    while(exp < n -1) {
        if (modulo(a, exp, n) == n -1) {
            return true;
        }
        exp <<= 1;
    }
    return false;
}

bool miller_rabin(int n, int k = 2) {
    int a = 0;
    for(int i = 0; i<k; i++) {
        a = randombytes_uniform(n-1)+2;
        if(!(singleTest(n, a))) {
            return false;
        }
    }
    return true;
}

int primeFinder(int max) {
    int count = 0;

    for(int i=2; i<=max; i++) {
        bool value = miller_rabin(i);
        if(value) {
            count++;
        }
    }

    return count;
}


int main(int argc, char *argv[]){
    if(argc < 2) {
        cout << "You must supply a value\n";
    }
    const int MAX = atoi(argv[1]);

    // cout << miller_rabin(max) << std::endl;
    cout << primeFinder(MAX) << std::endl;

    return 0;
}