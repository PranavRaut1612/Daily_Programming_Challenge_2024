#include<iostream>
using namespace std;
void sort012(int arr[],int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(arr[mid]==2){
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
        else if(arr[mid]==0){
            int temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;
            mid++;
            low++;
        }
        else mid++;
    }
}
int main(){
    int arr[] = {0, 1, 2, 1, 0, 2, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Unsorted Array : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    sort012(arr,n);
    cout<<endl<<"Sorted Array : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}