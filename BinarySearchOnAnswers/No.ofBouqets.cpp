//leetcode 1482. Minimum Number of Days to Make m Bouquets

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    bool possible(vector<int>nums,int day,int m, int k){
        int count=0,bouqets=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=day) count++; //if the flower is bloomed then we can count it towards our bouquet, if it is not bloomed then we cannot count it towards our bouquet
            else{
                bouqets+=(count/k); //this converts the count of flowers bloomed till now into no. of bouqets we can make with those bloomed flowers
                count=0;
            }
        }
        bouqets+=(count/k);
        if(bouqets>=m) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        if((long long)m*k>bloomDay.size()) return -1;
        while(low<=high){
            int mid = low + (high - low) / 2;
            bool ispossible=possible(bloomDay,mid,m,k);
            if(!ispossible) low=mid+1;
            else high=mid-1; 
        }
        return low;
    }


int main()
{
    vector<int> bloomDay={1,10,3,10,2};
    int m=3,k=1;
    //k is the number of flowers required to make a bouquet, m is the number of bouquets required, bloomDay is the array which contains the day on which each flower will bloom. We have to find the minimum number of days required to make m bouquets with k flowers in each bouquet. If it is not possible to make m bouquets with k flowers in each bouquet, we have to return -1.
    int ans = minDays(bloomDay,m,k);
    cout << ans;
    return 0;
}