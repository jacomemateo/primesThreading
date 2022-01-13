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
        exp >> 1;
    }

    if (modulo(a, exp, n) == 1 ) {
        return true;
    }
    while(exp < n -1) {
        if (modulo(a, exp, n) == n -1) {
            return true;
        }
        exp << 1;
    }
    return false;
}




int main() {
    if (sodium_init() < 0) {
        /* panic! the library couldn't be initialized, it is not safe to use */
    }
    
    int die = randombytes_uniform(100);
    cout << die;

    return 0;
}