#include<iostream>
#include<vector>
using namespace std;
int findDuplicate(int arr[],int n) {
    vector<bool> check(n+1,false);
    for(int i=0;i<n;i++){
        int idx = arr[i] - 1;
        if(check[idx]==false) check[idx] = true;
        else return arr[i];
    }
    return 100;
}
int main(){
    int arr[] = {3,1,3,4,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Duplicate number is "<<findDuplicate(arr,n);
}