//leetcode 930. Binary Subarrays With Sum

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int atmost(vector<int>nums,int goal){
    int maxlen=0;
    int n=nums.size();
    int count=0;
    int l=0;
    int sum=0;
    for(int r=0;r<n;r++){
        sum+=nums[r];
        while(sum>goal){
            sum-=nums[l];
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
    vector<int>nums={1,0,1,0,1};
    int ans=findsubaaray(nums,2);
    cout<<ans;
}