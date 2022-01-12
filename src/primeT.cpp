#include <iostream>
#include <thread>
#include <future>
using std::thread;
using std::cout;
using std::async;
using std::future;


int findPrime(int min, int max) {
    int count, num, c = 0;
    for(int i=min; i<=max; i++)
        {
        num = i;
        count = 0;  
        for(int x = 1; x <= num; x++) {
        if(num%x == 0) {
            count++;
        }
        }
        if(count == 2) {  
            c++;
        }  
    }

    return c;
}


int main(int argc, char *argv[]) {
    int primes = 0;

    const auto processor_count = std::thread::hardware_concurrency();
    const int MAX = atoi(argv[1]);
    const int MINIMUM_VALUES = processor_count*2;
    const int MIN = 2;
    if((MAX-MIN)<MINIMUM_VALUES) {
        primes = findPrime(MIN, MAX);
    }
    else {
        int arr[processor_count][2] = {{}};

        int intervals = MAX/processor_count;
        arr[0][0] = MIN;
        arr[0][1] = intervals;

        for(int i=1; i<=processor_count-1; i++) {
            arr[i][0] = arr[i-1][1] + 1;
            arr[i][1] = arr[i-1][1] + intervals;
        }
        arr[processor_count-1][1] = MAX;

        future<int> values[processor_count] = {};
        for(int i=0; i<processor_count; i++) {
            values[i] = async(findPrime, arr[i][0], arr[i][1]);
        }
        for(int i=0; i<processor_count; i++) {
            primes+=values[i].get();
        }

    }

    cout << primes << std::endl;
    return 0;
}