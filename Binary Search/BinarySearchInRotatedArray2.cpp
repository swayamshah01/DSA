// Binary Search in Rotated Sorted Array II
//81

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;

    if (obj.search(nums, target)) {
        cout << "Target found\n";
    } else {
        cout << "Target not found\n";
    }

    return 0;
}

//it contains duplicate elements so we have to handle the case when low,mid and high are same then we can not decide which half is sorted so we will just move low and high towards the middle and continue the search.
//the old method only fails when low,mid and high are same because we can not decide which half is sorted so we will just move low and high towards the middle and continue the search.
//so we will just add a condition to check if low,mid and high are same then we will just move low and high towards the middle and continue the search.