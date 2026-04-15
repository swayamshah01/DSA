// leetcode : 1248. Count Number of Nice Subarrays
// nice subarray is a subarray that contains exactly k odd numbers. Given an array of integers nums and an integer k, return the number of nice sub-arrays.


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int atmost(vector<int>nums,int k){
    int maxlen=0;
    int n=nums.size();
    int count=0;
    int l=0;
    int odd=0;
    for(int r=0;r<n;r++){
       if(nums[r]%2==1){
           odd++;
       }
        while(odd>k){
            if(nums[l]%2==1){
                odd--;
            }
            l++;
        }
        count+=r-l+1;
    }
    return count;
}
int findsubaaray(vector<int>nums,int k){
    return atmost(nums,k)-atmost(nums,k-1);
}
int main(){
    vector<int>nums={1,1,2,1,1};
    int ans=findsubaaray(nums,3);
    cout<<ans;
}