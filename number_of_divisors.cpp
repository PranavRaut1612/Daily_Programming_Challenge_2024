#include <iostream>
#include <cmath> 
using namespace std;

int numberOfDivisor(int n) {
    if (n == 1) return 1;
    int count = 0;

    // Check for each number from 1 to sqrt(n)
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            count++; // Count i as a divisor
            if (i != n / i) {
                count++; // Count n/i as a divisor
            }
        }
    }
    return count;
}

int main() {
    long long n = 100;
    cout << numberOfDivisor(n) << endl; 
    return 0;
}
