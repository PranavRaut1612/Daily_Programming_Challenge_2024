#include<iostream>
#include<string>
using namespace std;
bool checkPal(const string &s, int low, int high) {
    while (low < high) {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}
string longestPalindrome(string s) {
    // Get length of input string
    int n = s.size();

    // All substrings of length 1 are palindromes
    int res = 1, start = 0;

    // Nested loop to mark start and end index
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            
            // Check if the current substring is 
            // a palindrome
            if (checkPal(s, i, j) && (j - i + 1) > res) {
                start = i;
                res = j - i + 1;
            }
        }
    }
    return s.substr(start, res); 
}
int main(){
    string s = "babad";
    cout<<longestPalindrome(s);
}