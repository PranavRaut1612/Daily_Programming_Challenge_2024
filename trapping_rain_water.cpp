#include<iostream>
#include<vector>
using namespace std;
int trap(vector<int>& height) {
        int n = height.size();
        // previous greatest element array
        int arr[n];
        arr[0] = -1;
        int max = height[0];
        for(int i=1;i<n;i++){
            arr[i]=max;
            if(height[i]>max) max = height[i];
        }
        arr[n-1] = -1;
        max = height[n-1];
        for(int i=n-2;i>=0;i--){
            if(max<arr[i]) arr[i] = max;
            if(height[i]>max) max = height[i];
        }
        // calculating water
        int water = 0;
        for(int i=1;i<n-1;i++){
            if(height[i]<arr[i]) water+= (arr[i]-height[i]);
        }
        return water;
    }
int main(){
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(heights);
}