#include <iostream>
#include <vector>
using namespace std;
//leetcode : 287. Find the Duplicate Number
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];         
            fast = nums[nums[fast]];    
        } while (slow != fast);

        
        slow = nums[0];               
        while (slow != fast) {
            slow = nums[slow];         
            fast = nums[fast];        
        }
        
        return slow; 
    }
};
int main() {
    Solution s;
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << s.findDuplicate(nums) << endl; // Output should be 2
    return 0;
}

//slow fast imagine in list to detect the cycle starting point
//so here  the duplictae number is the starting point of the cycle and we are using the same logic to find the duplicate number in the array as well

//how list?
// index as node and value as pointer
// 0 1 2 3 4
// 1 3 4 2 2

// so 0->1->3->2->4->2
// so here 2 is the duplicate number and also the starting point of the cycle