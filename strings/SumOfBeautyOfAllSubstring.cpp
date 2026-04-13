//leetcode 1781

#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);  

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int maxi = 0, mini = INT_MAX;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }

                total += (maxi - mini);
            }
        }

        return total;
    }
};
int main() {
    Solution solution;
    string input = "aabcbaa";
    int output = solution.beautySum(input);
    cout << "Total Beauty Sum of All Substrings: " << output << endl; 
    return 0;
}

// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.

 