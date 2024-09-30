#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int firstElementToRepeatKTimes(const vector<int>& arr, int k) {
    unordered_map<int, int> freq;

    for (int i = 0; i < arr.size(); i++) {
        freq[arr[i]]++;

        // We only check for frequency exactly equal to k after incrementing
        if (freq[arr[i]] == k) {
            // Now, ensure this element does not appear more than k times later
            int count = 0;
            for (int j = 0; j < arr.size(); j++) {
                if (arr[j] == arr[i]) {
                    count++;
                }
                if (count > k) {
                    break;  // This element exceeds k later
                }
            }
            if (count == k) {
                return arr[i];
            }
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 2, 2, 5, 5};
    int k = 2;

    int result = firstElementToRepeatKTimes(arr, k);

    if (result != -1) {
        cout << "First element to repeat exactly " << k << " times is: " << result << endl;
    } else {
        cout << "No element repeats exactly " << k << " times or frequency exceeds k." << endl;
    }

    return 0;
}
