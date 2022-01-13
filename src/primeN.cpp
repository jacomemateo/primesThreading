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

bool miller_rabin(int n, int k = 40) {
    int a = 0;
    for(int i = 0; i<k; i++) {
        a = randombytes_uniform(n-1)+2;
        if(!(singleTest(n, a))) {
            return false;
        }
    }
    return true;
}


int main() {
    cout << miller_rabin(96) << std::endl;

    return 0;
}