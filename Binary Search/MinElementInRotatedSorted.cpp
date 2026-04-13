//leetcode 153
// Find Minimum in Rotated Sorted Array

#include <bits/stdc++.h>
using namespace std;
//min always lie in unsorted part
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid element is greater than high → min is in right half
            if (nums[mid] > nums[high]) {//left sorted
                low = mid + 1;
            } 
            // Else → min is in left half (including mid)
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};

int main() {
    Solution obj;

    vector<int> nums = {4,5,6,7,0,1,2};

    cout << "Minimum element: " << obj.findMin(nums) << endl;

    return 0;
}