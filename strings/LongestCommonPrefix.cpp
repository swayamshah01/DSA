#include <iostream>
#include <vector>
#include <string>
using namespace std;

//leetcode : 14. Longest Common Prefix
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Iterate through each character of the first word
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];  // this is 1st word and than character
            
            // Check this character against all other words
            for (int j = 1; j < strs.size(); j++) {
                // If the word is too short OR characters don't match
                if (i == strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0]; //if loop gets executed fully than there is no mismatch so we return entire 1st word
    }


int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs) << endl; 
    return 0;
}