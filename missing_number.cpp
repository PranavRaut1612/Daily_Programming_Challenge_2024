#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int missing_number(vector<int>& arr,int size){
    // Checking approach
    // sort(arr.begin(),arr.end());
    // for(int i=0;i<size;i++){
    //     if(arr[i]!=i+1){
    //         return i+1;
    //     }
    // }
    // return -1;

    // Mathematical Approach
    int n = size+1;
    int totalsum = n*(n+1)/2;
    int sum = 0;
    for(int i=0;i<size;i++){
        sum += arr[i];
    }
    return totalsum-sum;
}
int main(){
    vector<int> arr = {1, 2, 4, 5};
    int size = arr.size();
    cout<<"Missing Integer is "<<missing_number(arr,size);
}    