// book allocation : we have to allocate books to students such that the maximum number of pages assigned to a student is minimum. We can use binary search to find the minimum maximum number of pages. We can check if it is possible to allocate books with a given maximum number of pages or not. If it is possible, we can try for a smaller maximum number of pages, otherwise we can try for a larger maximum number of pages.
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool isPossibleAllocation(vector<int>& nums, int max_allowed, int k) {
    int students = 1;
    int current_pages = 0;
    
    for(int i = 0; i < nums.size(); i++) {
        // If a single book is bigger than the limit, it's impossible
        if(nums[i] > max_allowed) return false; 
        
        if(current_pages + nums[i] <= max_allowed) {
            current_pages += nums[i];
        } else {
            students++; // Assign to next student
            current_pages = nums[i];
        }
    }
    // Is the number of students used within the limit?
    return students <= k;
}

int BookAllocation(vector<int>& nums, int k) {
    if (k > nums.size()) return -1; // Cannot have more students than books

    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans = 0;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isPossibleAllocation(nums, mid, k)) {
            ans = mid;      // Found a possible max, try to find a smaller one
            high = mid - 1;
        } else {
            low = mid + 1;  // Not possible, need a larger maximum
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {12, 34, 67, 90};
    int students = 2;
    cout << BookAllocation(nums, students); // Expected Output: 113
    return 0;
}


//split array largest sum : we have to split the array into k subarrays such that the largest sum among these subarrays is minimum. We can use binary search to find the minimum largest sum. We can check if it is possible to split the array with a given largest sum or not. If it is possible, we can try for a smaller largest sum, otherwise we can try for a larger largest sum.

// painters partition : we have to paint n boards with k painters such that the time taken to paint all boards is minimum. We can use binary search to find the minimum time taken. We can check if it is possible to paint all boards with a given time or not. If it is possible, we can try for a smaller time, otherwise we can try for a larger time.

// all three have same logic, just different context. We can use the same isPossible function for all three problems by changing the condition according to the problem statement.