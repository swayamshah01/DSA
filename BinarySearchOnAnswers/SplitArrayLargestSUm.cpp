//leetcode : 410. Split Array Largest Sum
// Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.


#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

    bool isPossible(vector<int>nums,int k,int max_sum){
        int cntsubarray=1;
        int currsum=0;
        for(int i=0;i<nums.size();i++){
            if(currsum+nums[i]<=max_sum){
                currsum+=nums[i];
            }else{
                cntsubarray++;
                currsum=nums[i];
            }
        }
        if(cntsubarray<=k)return true;
        else return false;
    }
    
    int splitArray(vector<int>& nums, int k) {
         int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(),0);
    int ans=0;
    while(low<=high){
        int mid=low+((high-low)/2);
        if(isPossible(nums,k,mid)==true){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
    }


int main() {
    vector<int> nums = {7,2,5,10,8};
    int k = 2;
    int ans = splitArray(nums, k);
    cout << ans; 
    return 0;
}