//leetcode 1283. Find the Smallest Divisor Given a Threshold

// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and divide all the array elements by it and sum up the result of the division. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int isvalid(vector<int>nums,int divisor,int h){
    long long ans=0;
    for(int i=0;i<nums.size();i++){
        ans += (nums[i] + divisor - 1) / divisor; 
    }
    if(ans<=h) return 1;
    else return -1;
}

int smallestDivisor(vector<int> nums , int h){
    int low=1;
    int high=*max_element(nums.begin(),nums.end());
    while(low<=high){
        int mid=low + (high - low) / 2;
        int isValid=isvalid(nums,mid,h);
        if(isValid==1){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
}

int main()
{
    vector<int>nums={44,22,33,11,1};
    int h=5;
    int ans = smallestDivisor(nums,h);
    cout << ans;
    return 0;
}