#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(const string& s) {
    stack<char> st;
    unordered_map<char, char> matchingBracket = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char ch : s) {
        // If it's a closing bracket
        if (matchingBracket.find(ch) != matchingBracket.end()) {
            // Check if the stack is not empty and if the top matches the correct opening bracket
            if (!st.empty() && st.top() == matchingBracket[ch]) {
                st.pop();
            } else {
                return false;
            }
        } else {
            // If it's an opening bracket, push it onto the stack
            st.push(ch);
        }
    }
    
    // In the end, the stack should be empty if the string is valid
    return st.empty();
}

int main() {
    string s = "{[()]}"; // Example input
    if (isValid(s)) {
        cout << "The string is valid.\n";
    } else {
        cout << "The string is invalid.\n";
    }
    
    return 0;
}
