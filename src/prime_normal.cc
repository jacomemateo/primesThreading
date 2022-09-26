#include <iostream>

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

int main() {
    int max = 100;
    int count = findPrime(2, max);

    std::cout << count << "\n";
    return 0;
}
