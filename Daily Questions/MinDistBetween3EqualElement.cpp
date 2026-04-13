//leetode 3740
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto &p : mp) {
            vector<int> &v = p.second;

            int l = 0;
            for (int r = 0; r < v.size(); r++) {

                // maintain window size = 3
                if (r - l + 1 > 3) {
                    l++;
                }

                if (r - l + 1 == 3) {
                    int dist = 2 * (v[r] - v[l]); // distance between 3 equal elements is 2 * (last index - first index)
                    ans = min(ans, dist);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 1,3};
    cout << sol.minimumDistance(nums) << endl; 
    return 0;
}



// 🧠 Given Formula

// For a triplet (i, j, k):

// distance = |i - j| + |j - k| + |k - i|
// 🔥 Key Observation

// We always take:

// i < j < k

// So absolute values simplify:

// |i - j| = (j - i)
// |j - k| = (k - j)
// |k - i| = (k - i)
// 📌 Now substitute
// distance = (j - i) + (k - j) + (k - i)
// ✂️ Simplify step-by-step
// = j - i + k - j + k - i

// Cancel +j and -j:

// = k - i + k - i
// = 2 * (k - i)