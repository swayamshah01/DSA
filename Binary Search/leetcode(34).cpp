// desc : this code is for finding the first and last position of an element in a sorted array using binary search (lower_bound and upper_bound functions)

class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        int lb=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        if(lb==x || arr[lb]!=x) return {-1,-1};
        int ub=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
        return {lb,ub-1};
    }
};

//finding the first and last position of an element in a sorted array