#include <iostream>
#include<vector>
using namespace std;

int UpperBound(vector<int>& nums, int x){
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = n; // default if no element > x

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(nums[mid] > x){
            ans = mid;          // store answer
            high = mid - 1;     // move left
        }
        else{
            low = mid + 1;      // move right
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,3,3,5,8,8,10,10,11};

    int ans = UpperBound(nums, 3);

    cout << ans;

    return 0;
}

//c++
//stl
// upper_bound(arr.begin(),arr.end(),x)-arr.begin()