#include<iostream>
#include<vector>
using namespace std;
vector<int> primeFac(int n){
    vector<int> factors;
    while(n%2==0){
        factors.push_back(2);
        n/=2;
    }
    for(int i=3;i*i<=n;i+=2){
        while(n%i==0){
            factors.push_back(i);
            n/=i;
        }
    }
    if(n>2) factors.push_back(n);
    return factors;
}
int main(){
    int n = 123456;
    vector<int> factors = primeFac(n);
    cout<<"Prime Factors are : ";
    for(int factor: factors){
        cout<<factor<<" ";
    }
}