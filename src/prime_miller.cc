#include <iostream>
#include <thread>
#include <future>
#include <sodium.h>
using std::thread;
using std::cout;
using std::async;
using std::future;

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


int main(int argc, char *argv[]) {
    if(argc < 2) {
        cout << "You must supply a value\n";
    }
    const int MAX = atoi(argv[1]);

    int primes = 0;

    const auto processor_count = std::thread::hardware_concurrency();
    const int MINIMUM_VALUE = processor_count*2;
    const int MIN = 2;
    if((MAX-MIN)<MINIMUM_VALUE) { // Checks if the range you specified is greater than the min value you can calculate using your cores
        primes = primeFinder(MIN, MAX);
    }
    else {
        int arr[processor_count][2] = {{}};

        int intervals = MAX/processor_count;
        arr[0][0] = MIN;
        arr[0][1] = intervals;

        for(int i=1; i<=processor_count-1; i++) { // Creates a list of intervals to calculate
            arr[i][0] = arr[i-1][1] + 1;
            arr[i][1] = arr[i-1][1] + intervals;
        }
        arr[processor_count-1][1] = MAX;

        future<int> values[processor_count] = {};
        for(int i=0; i<processor_count; i++) { // Calls the findPrime function and calculates
            values[i] = async(primeFinder, arr[i][0], arr[i][1]);
        }
        for(int i=0; i<processor_count; i++) { // Adds up results, this needed to be in a separate loop or else the performace would be the same as primeN.cpp
            primes+=values[i].get();
        }

    }

    cout << primes << std::endl;
    return 0;
}
