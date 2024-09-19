#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    
    // Create a vector of pairs (sorted string, original string)
    vector<pair<string, string>> sortedStrs;
    
    // For each string, store the sorted version and original string
    for (string s : strs) {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end());
        sortedStrs.push_back({sortedStr, s});
    }
    
    // Sort the vector of pairs based on the sorted string
    sort(sortedStrs.begin(), sortedStrs.end());
    
    // To group the anagrams, iterate over the sorted vector
    vector<vector<string>> result;
    vector<string> currentGroup;
    
    for (int i = 0; i < n; i++) {
        if (i == 0 || sortedStrs[i].first != sortedStrs[i - 1].first) {
            // If the current sorted string is different from the previous one,
            // start a new group
            if (!currentGroup.empty()) {
                result.push_back(currentGroup);
            }
            currentGroup = {sortedStrs[i].second};  // New group with current string
        } else {
            // If the current sorted string is the same as the previous one, add to the group
            currentGroup.push_back(sortedStrs[i].second);
        }
    }
    
    // Don't forget to add the last group
    if (!currentGroup.empty()) {
        result.push_back(currentGroup);
    }
    
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    // Call the function
    vector<vector<string>> final = groupAnagrams(strs);
    
    // Print the result
    for (const auto& group : final) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
