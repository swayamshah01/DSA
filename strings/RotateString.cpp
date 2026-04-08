#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;

        string temp = s + s;//when we add same string than all the possible rotations of that string will be present in the temp string so we just need to check if goal is present in temp or not

        return temp.find(goal) != string::npos; //npos means not found if it is not found then it will return npos which is a very large number so if it is not equal to npos that means it is found and we return true otherwise false
    }
};


//method 2 using array rotation logic we did earlier

class Solution2 {
public:
    void leftRotate(string &s, int k) {
        int n = s.size();

        reverse(s.begin(), s.begin() + k);
        reverse(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
    }

    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        int n = s.size();

        for(int k = 0; k < n; k++) {
            string temp = s;  // copy original

            leftRotate(temp, k);

            if(temp == goal) return true;
        }

        return false;
    }
};


int main() {
    Solution s;
    Solution2 s2;
    string str1 = "abcde";
    string goal = "deabc";
    cout << s.rotateString(str1, goal) << endl; // Output should be 1 (true)
    cout << s2.rotateString(str1, goal) << endl; // Output should be 1 (true)
    return 0;
}