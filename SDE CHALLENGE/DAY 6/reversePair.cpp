//leetcod 493

// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where:

// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].
 

// Example 1:

// Input: nums = [1,3,2,3,1]
// Output: 2
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int merge(vector<int>& nums, int low, int mid, int high) {

        int cnt = 0;

        int right = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (right <= high &&
                   nums[i] > 2LL * nums[right]) {
                right++;
            }

            cnt += (right - (mid + 1));
        }

        vector<int> temp;

        int left = low;
        right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            }
            else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left++]);
        }

        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return cnt;
    }

    int mergesort(vector<int>& nums, int low, int high) {

        if (low >= high)
            return 0;

        int mid = (low + high) / 2;

        int count = 0;

        count += mergesort(nums, low, mid);
        count += mergesort(nums, mid + 1, high);

        count += merge(nums, low, mid, high);

        return count;
    }

    int reversePairs(vector<int>& nums) {

        return mergesort(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 3, 2, 3, 1};
    int result = obj.reversePairs(nums);
    cout << "Number of reverse pairs: " << result << endl;
    return 0;
}