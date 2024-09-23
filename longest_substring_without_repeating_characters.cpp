#include<iostream>
#include<string>
#include<vector>
using namespace std;
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int start = 0;
    // int end = 0;
    int maxlen = 0;
    vector<int> freq(128,0);
    for(int end=0;end<n;end++){
        freq[s[end]]++;
        while(freq[s[end]]>1){
            freq[s[start]]--;
            start++;
        }
        maxlen = max(maxlen,end-start+1);
    }
    return maxlen;
}
int main(){
    string s = "abcabcbb";
    cout<<"Length Of Longest Substring = "<<lengthOfLongestSubstring(s);
}