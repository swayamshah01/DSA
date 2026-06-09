#include <iostream>
#include <vector> 
#include <unordered_map> 
using namespace std; 

vector<int> twosum(vector<int> nums, int x) { 
    unordered_map<int, int> mpp; 
    
    for (int i = 0; i < nums.size(); i++) { 
        int sum = nums[i]; 
        int rem = x - sum; 
        
        if (mpp.find(rem) != mpp.end()) { 
            return {i, mpp[rem]}; 
        } 
        mpp[nums[i]] = i; 
    } 
    return {}; 
} 

int main() { 
    vector<int> nums = {2, 7, 11, 15}; 
    int target = 9; 
    vector<int> ans = twosum(nums, target); 
    if (!ans.empty()) {
        cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }
    
    return 0; 
}