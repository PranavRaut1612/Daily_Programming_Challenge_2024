#include<iostream>
#include<vector>
#include<string>
using namespace std;
string reverseWords(string s) {
    int n = s.size();
    if(n==1) return s;
    string ans = "";
    vector<string> v;
    int i=0;
    string temp = "";
    for(int i=0;i<n;i++){
        if(s[i]!=' '){
            temp+=s[i];
        }
        else if(!temp.empty()){
            v.push_back(temp);
            temp = "";
        }
    }
    if(!temp.empty()) v.push_back(temp);
    for(int i=v.size()-1;i>=0;i--){
        ans+=v[i];
        if(i!=0) ans+=" ";
    }
    return ans;
}
int main(){
    string s = "the sky is blue";
    string ans = reverseWords(s);
    cout<<"Original String : ";
    cout<<s<<endl;
    cout<<"Reversed String : ";
    cout<<ans;
}