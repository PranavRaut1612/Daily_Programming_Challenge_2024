#include <iostream>
using namespace std;

// Function to calculate n-th Fibonacci number using Dynamic Programming
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    
    // Create an array to store Fibonacci numbers
    int dp[n+1];
    
    // Initialize base cases
    dp[0] = 0;
    dp[1] = 1;
    
    // Fill the dp array in a bottom-up manner
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "The " << n << "-th Fibonacci number is: " << fibonacci(n) << endl;

    return 0;
}
