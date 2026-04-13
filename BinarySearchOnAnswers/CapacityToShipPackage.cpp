//leetcode: 1011. Capacity To Ship Packages Within D Days
// A conveyor belt has packages that must be shipped from one port to another within days days. The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship. Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.


#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
    int checkDays(vector<int>weights,int capacity){
        int day=1,load=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            if(load+weights[i]<=capacity){
                load+=weights[i];
            }else{
                day++;
                load=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=low+((high-low)/2);
            if(checkDays(weights,mid)>days){
                low=mid+1;
            }else{
                high=mid-1;

            }
        }
        return low;
    }


int main()
{
    vector<int>weights={1,2,3,4,5,6,7,8,9,10};
    int days=5;

    int ans = shipWithinDays(weights, days);
    cout << ans;
    return 0;
}