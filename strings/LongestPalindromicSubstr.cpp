// leetcode 5

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        
        int start = 0, maxLen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd length (e.g., "aba")
            expand(s, i, i, start, maxLen);
            // Case 2: Even length (e.g., "baab")
            expand(s, i, i + 1, start, maxLen);
        }
        
        return s.substr(start, maxLen);
    }

private:
    void expand(string& s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            int currentLen = right - left + 1;
            if (currentLen > maxLen) {
                maxLen = currentLen;
                start = left;
            }
            left--;
            right++;
        }
    }
};
int main() {
    Solution solution;
    string input = "babad";
    string output = solution.longestPalindrome(input);
    cout << "Longest Palindromic Substring: " << output << endl; // Output can be "aba" or "bab"
    return 0;
}

//concept : expand around centre
// i,i -> odd length same mid 
// i,i+1-> even length two mid