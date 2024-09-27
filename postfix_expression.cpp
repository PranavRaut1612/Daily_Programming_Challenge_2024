#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(const string &expression) {
    stack<int> s;
    stringstream ss(expression);
    string token;

    // Split the expression by spaces
    while (ss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            // If the token is a number, push it onto the stack
            s.push(stoi(token));
        } else {
            // Token is an operator, pop two numbers from the stack
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            if (token == "+") {
                s.push(a + b);
            } else if (token == "-") {
                s.push(a - b);
            } else if (token == "*") {
                s.push(a * b);
            } else if (token == "/") {
                s.push(a / b);  // Integer division
            }
        }
    }

    // The final result will be the only element in the stack
    return s.top();
}

int main() {
    string expression = "2 1 + 3 *";  // Example postfix expression (equivalent to (2 + 1) * 3)
    int result = evaluatePostfix(expression);
    cout << "Result: " << result << endl;  // Output: 9
    return 0;
}
