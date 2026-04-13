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

        return low;
    }
};
//we just need to return the index of minimum element as that will be the number of times the array is rotated.
int main() {
    Solution obj;

    vector<int> nums = {3,4,5,1,2};

    cout << "No.of times array is rorated is: " << obj.findMin(nums) << endl;

    return 0;
}