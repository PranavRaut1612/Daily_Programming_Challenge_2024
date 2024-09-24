#include<iostream>
using namespace std;
long long lcm(int a,int b){
    int m = a;
    int n = b;
    while(b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    int gcd = a;
    long long lcm = (1LL*m*n)/gcd;
    return lcm;
}
int main(){
    int a = 123456;
    int b = 789012;
    cout<<lcm(max(a,b),min(a,b));
}