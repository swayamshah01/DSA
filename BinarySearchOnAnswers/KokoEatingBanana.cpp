//leetcode 875. Koko Eating Bananas
// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

long long calchr(vector<int>& nums, int banana_perhr){
        long long hr = 0;

        for(int i = 0; i < nums.size(); i++){
            hr += (nums[i] + banana_perhr - 1) / banana_perhr; //use this instead of ceil(nums[i] / (double)banana_perhr) to avoid floating point operations
        }

        return hr;
    }

    int minEatingSpeed(vector<int>& nums, int h) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = low + (high - low) / 2;

            long long totalhr = calchr(nums, mid);

            if(totalhr <= h){
                high = mid - 1; //we want minimum possible answer
            }else{
                low = mid + 1;
            }
        }

        return low;
    };

int main()
{
    vector<int>nums={3,6,7,11};
    int h=8;
    int ans = minEatingSpeed(nums, h);
    cout << ans;
    return 0;
}