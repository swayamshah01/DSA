#include <iostream>
#include <vector>
using namespace std;
//leetcode : 713. Subarray Product Less Than K
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        int l=0;
        long long product=1;
        for(int r=0;r<n;r++){
            product *=nums[r];
            while(product>=k && l<=r){
                product/=nums[l];
                l++;
            }
            count+=r-l+1;
        }
        return count;
    }
};
int main()  {
    Solution s;
    vector<int> nums={10,5,2,6};
    int k=100;
    cout<<s.numSubarrayProductLessThanK(nums,k);
}