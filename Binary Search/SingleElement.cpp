// Single Element in a Sorted Array
//540

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Edge cases
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int low = 1, high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If mid is the single element
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // Left side is valid (pattern holds)
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                low = mid + 1;
            }
            // Right side is valid → go left
            else {
                high = mid - 1;
            }
        }

        return -1; 
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    cout << "Single element: " << obj.singleNonDuplicate(nums) << endl;

    return 0;
}