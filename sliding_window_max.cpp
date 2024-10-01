#include<iostream>
#include<vector>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return {};

        vector<int> left(n), right(n);
        vector<int> ans;

        // Initialize left and right max arrays
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];

        // Fill left array: Maximum of every block from left to right
        for (int i = 1; i < n; i++) {
            // Start a new block every k elements
            if (i % k == 0) {
                left[i] = nums[i];  // Start of a new block
            } else {
                left[i] = max(left[i - 1], nums[i]);
            }
        }

        // Fill right array: Maximum of every block from right to left
        for (int i = n - 2; i >= 0; i--) {
            // End a block every k elements
            if ((i + 1) % k == 0) {
                right[i] = nums[i];  // End of a block
            } else {
                right[i] = max(right[i + 1], nums[i]);
            }
        }

        // Construct the output
        for (int i = 0; i <= n - k; i++) {
            ans.push_back(max(left[i + k - 1], right[i]));
        }

        return ans;
    }
int main(){
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
