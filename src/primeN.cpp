#include <iostream>
using std::cout;

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

int main(int argc, char *argv[])
{
    const int max = atoi(argv[1]);
    int count = findPrime(2, max);

    cout << count << "\n";
    return 0;
}