#include <iostream>
#include <string>
#include <climits>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        long result = 0; // Use long to detect overflow
        int sign = 1;

        // 1. Skip spaces
        while (i < n && s[i] == ' ') i++;

        // 2. Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Your "while till character comes" loop
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // 4. Handle Overflow immediately
            if (result * sign >= INT_MAX) return INT_MAX;
            if (result * sign <= INT_MIN) return INT_MIN;
            
            i++;
        }

        return (int)(result * sign);
    }
};

int main() {
    Solution solution;
    string input = "   -42";
    int output = solution.myAtoi(input);
    cout << "Output: " << output << endl; // Output: -42
    return 0;
}