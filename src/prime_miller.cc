#include <iostream>
#include <thread>
#include <future>
#include <random>

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
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(0, n-1);
        a = dist6(rng) + 2;
        if(!(singleTest(n, a))) {
            return false;
        }
    }
    return true;
}

int primeFinder(int min, int max) {
    int count = 0;

    for(int i=min; i<=max; i++) {
        bool value = miller_rabin(i);
        if(value) {
            count++;
        }
    }

    return count;
}


int main() {
    const int MAX = 100;

    int primes = primeFinder(2, MAX);
    std::cout << primes << std::endl;
    return 0;
}
