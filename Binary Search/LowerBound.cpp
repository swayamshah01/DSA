//smallest index of an element in the array which is greater than or equal to the target
//arr[idx]>=target
#include <iostream>
#include<vector>
#include<climits>
using namespace std;

int LowerBound(vector<int>& nums, int x){
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = n; 

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(nums[mid] >= x){
            ans = mid;          
            high = mid - 1;  
        }
        else{
            low = mid + 1;   
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,3,3,5,8,8,10,10,11};
    int ans = LowerBound(nums, 1);
    cout << ans;
     return 0;
}

//c++
//stl
// lower_bound(arr.begin(),arr.end(),x)-arr.begin()