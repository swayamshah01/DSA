#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};
//method 2 using frequency array
//if freq is same than if we add for s and subtrct for t than in the end if all the values are 0 than they are anagram otherwise not
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> freq(26, 0);

        for(char c : s) freq[c - 'a']++;
        for(char c : t) freq[c - 'a']--;

        for(int count : freq) {
            if(count != 0) return false;
        }

        return true;
    }
};

int main() {
    Solution s;
    Solution2 s2;
    string str1 = "anagram";
    string str2 = "nagaram";
    cout << s.isAnagram(str1, str2) << endl; // Output should be 1 (true)
    cout << s2.isAnagram(str1, str2) << endl; // Output should be 1 (true)
    return 0;
}