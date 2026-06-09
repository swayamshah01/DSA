//this code will give tle as n2


class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<int> ans;

        // Step 2: process queries
        for (int idx : queries) {
            int val = nums[idx];
            vector<int>& indices = mp[val];

            int minDist = INT_MAX;
            for (int j : indices) {
                if (j == idx) continue;

                int diff = abs(j - idx);
                int dist = min(diff, n - diff);

                minDist = min(minDist, dist);
            }

            if (minDist == INT_MAX) minDist = -1;

            ans.push_back(minDist);  
        }

        return ans;
    }
};





// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>
// using namespace std;
// class Solution {
// public:
//     vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
//         int n = nums.size();

//         unordered_map<int, vector<int>> mp;

//         // store indices
//         for (int i = 0; i < n; i++) {
//             mp[nums[i]].push_back(i);
//         }

//         vector<int> ans;

//         for (int idx : queries) {
//             int val = nums[idx];
//             vector<int>& v = mp[val];

//             if (v.size() == 1) {
//                 ans.push_back(-1);
//                 continue;
//             }

//             // binary search
//             auto it = lower_bound(v.begin(), v.end(), idx);

//             int minDist = INT_MAX;

//             // check right neighbor
//             if (it != v.end() && *it != idx) {
//                 int j = *it;
//                 int diff = abs(j - idx);
//                 minDist = min(minDist, min(diff, n - diff));
//             }

//             // check left neighbor
//             if (it != v.begin()) {
//                 int j = *(prev(it));
//                 if (j != idx) {
//                     int diff = abs(j - idx);
//                     minDist = min(minDist, min(diff, n - diff));
//                 }
//             }

//             // circular check: first and last
//             int first = v[0];
//             int last = v.back();

//             if (first != idx) {
//                 int diff = abs(first - idx);
//                 minDist = min(minDist, min(diff, n - diff));
//             }

//             if (last != idx) {
//                 int diff = abs(last - idx);
//                 minDist = min(minDist, min(diff, n - diff));
//             }

//             ans.push_back(minDist);
//         }

//         return ans;
//     }
// };

// int main() {
//     Solution s;
//     vector<int> nums = {1, 2, 3, 4, 1};
//     vector<int> queries = {0, 1, 2, 3, 4};
//     vector<int> result = s.solveQueries(nums, queries);

//     for (int dist : result) {
//         cout << dist << " ";
//     }
//     cout << endl;

//     return 0;
// }