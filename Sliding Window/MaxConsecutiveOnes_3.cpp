#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxOne(vector<int>nums,int k){
    int maxlen=0;
    int n=nums.size();
    int l=0;
    int zero=0;
    unordered_map<int,int>mpp;
    for(int r=0;r<n;r++){
        if(nums[r]==0){
            mpp[nums[r]]++;
            zero++;
        }
        while(zero>k){
            if(nums[l]==0){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                zero--;
            }
            l++;
        }
        if(zero<=k){
            maxlen=max(maxlen,r-l+1);
        }
    }
    return maxlen;
}
int main(){
    vector<int>nums={1,1,1,0,0,0,1,1,1,1,0};
    int ans=maxOne(nums,2);
    cout<<ans;
}