
#include <iostream>
#include <string>
using namespace std;

//leetcode : 1903. Largest Odd Number in String
class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main() {
    Solution s;
    string str = "52";
    cout << s.largestOddNumber(str) << endl; // Output should be "5"
    return 0;
}