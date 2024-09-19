#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve(string str, vector<string>& ans, int index) {
    if (index >= str.size()) {
        ans.push_back(str);
        return;
    }

    for (int i = index; i < str.size(); i++) {
        if (i != index && str[i] == str[index]) continue;
        swap(str[index], str[i]);
        solve(str, ans, index + 1);
    }
}

int main() {
    string str = "aab";
    sort(str.begin(), str.end());

    vector<string> ans;
    int index = 0;
    
    solve(str, ans, index);

    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}
