#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int currentSum = nums[0];
    int maxSum = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int ans = maxSubArray(nums);

    cout << "Maximum Subarray Sum: " << ans << endl;

    return 0;
}

// This code implements the Kadane's algorithm to find the maximum subarray sum in a given array of integers. The algorithm iterates through the array, keeping track of the current sum of the subarray and the maximum sum found so far. If the current sum becomes negative, it resets to the current element, as a negative sum would not contribute to a maximum sum in future iterations.
//kadane state that if sum is negative then we can ignore that sum (reset to 0) and start from next element. because negative sum will not contribute to maximum sum in future iterations.