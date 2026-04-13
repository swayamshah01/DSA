

//leetcode 1539. Kth Missing Positive Number
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= k) { // Changed < to <=
                k++;
            } else {
                break;
            }
        }
        return k;
    }
};
int main(){
    vector<int>arr={2,3,4,7,11};
    int k=5;
    Solution sol;
    int ans=sol.findKthPositive(arr,k);
    cout<<ans;
}
