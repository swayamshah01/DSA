// desc : this code is for finding the position where the target would be inserted in a sorted array using binary search (lower_bound function)

class Solution {
public:
    int searchInsert(vector<int>& arr, int x) {
        int ans=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        return ans;
    }
};

//finding the position where the target would be inserted in a sorted array
