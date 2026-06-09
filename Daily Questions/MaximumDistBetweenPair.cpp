#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int max_dist = 0;
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();

        while (i < n1 && j < n2) {
            if (i <= j && nums1[i] <= nums2[j]) {
                max_dist = max(max_dist, j - i);
                j++;
            } else {
                i++;
                if(i>j) j=i; //this is mot imp line
            }
        }

        return max_dist;
    }
};

int main() {
    Solution obj;
    vector<int> nums1 = {55, 30, 5, 4, 2};
    vector<int> nums2 = {100, 20, 10, 10, 5};

    int result = obj.maxDistance(nums1, nums2);
    cout << "Maximum Distance: " << result << endl;

    return 0;
}

// why imp?
// let say at any given time i++ has happend and j lagged behind i ,  the loop will still continue 
// i = 0, j = 0
// 55 <= 100 ✅ → j++
// i=0, j=1
// 55 <= 20 ❌ → i++
// i=1, j=1
// 30 <= 20 ❌ → i++
// i=2, j=1   ❗ PROBLEM STARTS HERE

// Now:

// i > j → invalid state
// ⚠️ Why this is dangerous?

// Now you're checking:

// nums1[2] <= nums2[1]

// But:

// i=2, j=1 → invalid pair (i > j)
// Still your loop continues 🤦‍♂️