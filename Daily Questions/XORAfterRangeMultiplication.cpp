// 3653. XOR After Range Multiplication quries I
//ou are given an integer array nums of length n and a 2D integer array queries of size q, where queries[i] = [li, ri, ki, vi].

// For each query, you must apply the following operations in order:

// Set idx = li.
// While idx <= ri:
// Update: nums[idx] = (nums[idx] * vi) % (109 + 7)
// Set idx += ki.
// Return the bitwise XOR of all elements in nums after processing all queries.

 

// Example 1:

// Input: nums = [1,1,1], queries = [[0,2,1,4]]

// Output: 4
#include <iostream>
#include <vector>
using namespace std;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int mod = 1e9 + 7;
        for(auto &q : queries) {
            int li = q[0];
            int ri = q[1];
            int ki = q[2];
            int vi = q[3];

            for(int i = li; i <= ri; i += ki) {
                nums[i] = (1LL * nums[i] * vi) % mod;
            }
        }

     
        int result = 0;
        for(int num : nums) {
            result ^= num;
        }

        return result;
    }
 int main() {
    vector<int> nums = {1, 1, 1};
    vector<vector<int>> queries = {{0, 2, 1, 4}};
    cout << xorAfterQueries(nums, queries) << endl; 
    return 0;
};