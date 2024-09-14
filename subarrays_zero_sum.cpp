#include<iostream>
#include<vector>
using namespace std;
void subarraySum(int arr[], int n) {
    int count = 0;
    cout<<"[";
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==0){
                count++;
                cout<<"("<<i<<","<<j<<"),";
            }
            // if(sum>k) break;
        }
    }
    cout<<"]"<<endl;
    cout<<"Count:"<<count<<endl;
}
int main(){
    int arr[] = {-3, 1, 2, -3, 4, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    subarraySum(arr,n);
}