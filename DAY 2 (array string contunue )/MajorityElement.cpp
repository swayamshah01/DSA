#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for(int num : nums){
            if(count == 0){
                candidate = num;
            }

            if(num == candidate){
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};

    Solution obj;
    int ans = obj.majorityElement(nums);

    cout << "Majority Element: " << ans << endl;

    return 0;
}
//moore voting algorithm is used to find the majority element in an array. The majority element is the element that appears more than n/2 times in the array, where n is the size of the array.