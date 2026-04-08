#include <iostream>
#include <string>   
#include <sstream>   // For stringstream
#include <vector>    // For vector
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s); // Automatically handles multiple spaces
        string word;
        vector<string> words;

        // Step 1: Extract words into a list
        while (ss >> word) {
            words.push_back(word);
        }

        // Step 2: Build the result string by walking backwards through the list
        string result = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i];
            if (i > 0) {
                result += " "; // Add space between words only
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    string str = "  Hello   World  ";
    cout << '"' << s.reverseWords(str) << '"' << endl; // Output should be "World Hello"
    return 0;
}