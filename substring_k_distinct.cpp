#include <iostream>
#include <unordered_map>
using namespace std;

int countSubstringsWithKDistinct(const string &s, int k) {
    int n = s.length();
    int result = 0;
    
    for (int i = 0; i < n; ++i) {
        unordered_map<char, int> freq;
        int distinctCount = 0;
        
        for (int j = i; j < n; ++j) {
            if (freq[s[j]] == 0) {
                distinctCount++;
            }
            
            freq[s[j]]++;
            
            if (distinctCount == k) {
                result++;
            } 
            else if (distinctCount > k) {
                break;
            }
        }
    }
    
    return result;
}

int main() {
    string s = "aabacbebebe";
    int k = 3;
    cout << "Number of substrings with exactly " << k << " distinct characters: "
         << countSubstringsWithKDistinct(s, k) << endl;
    return 0;
}
