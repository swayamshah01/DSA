#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mindist=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                mindist=min(mindist,abs(i-start));
            }
        }
        return mindist;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 5;
    int start = 3;
    cout << sol.getMinDistance(nums, target, start) << endl; 
    return 0;
}