#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>nums,int min_dist,int cows){
    int cntcows=1,lastcowat=nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]-lastcowat>=min_dist){
            cntcows++;
            lastcowat=nums[i];
        }
    }
    if(cntcows>=cows) return true;
    else return false;
}

int Cows(vector<int>nums,int cows){
    int low=0;
    int high=*max_element(nums.begin(),nums.end());
    sort(nums.begin(),nums.end());
    while(low<=high){
        int mid=low+((high-low)/2);
        if(isPossible(nums,mid,cows)==true) low=mid+1;
        else high=mid-1;
    }
    return high;
}

int main(){
    vector<int>stalls={0,3,4,7,10,9};
    int cow=4;
    int ans=Cows(stalls,cow);
    cout<<ans;
}

//this is agressive cows problem, we have to place cows in the stalls such that the minimum distance between any two cows is maximum. We can use binary search to find the maximum minimum distance. We can check if it is possible to place cows with a given minimum distance or not. If it is possible, we can try for a larger minimum distance, otherwise we can try for a smaller minimum distance.