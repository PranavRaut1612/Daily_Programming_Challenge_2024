#include<iostream>
using namespace std;
int k=0;
void leader_array(int arr[],int n,int ans[]){
    for(int i=0;i<n-1;i++){
        bool flag = false;
        int j = i+1;
        while(j<n){
            if(arr[j]>=arr[i]){
                flag = true;
                break;
            }
            j++;
        }
        if(flag==false){
            ans[k++] = arr[i];
        }
    }
    ans[k] = arr[n-1];
}
int main(){
    int arr[] = {16,17,4,3,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans[n];
    cout<<"Your Input Array Is :  ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    leader_array(arr,n,ans);
    cout<<"Your Leader Array Is : ";
    for (int i = 0; i <= k; i++) {
        cout << ans[i] << " ";
    }
}