#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int getsum(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;      
            sum += digit * digit;    
            n = n / 10;              
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = getsum(slow);             
            fast = getsum(getsum(fast));    
        } while (slow != fast);
        if(slow==1) return true;
        else return false;
    }
};
int main() {
    Solution s;
    int n = 19;
    cout << s.isHappy(n) << endl; // Output should be true
    return 0;
}
//leetcode : 202. Happy Number
//happy number is a number which eventually reaches 1 when replaced repeatedly by the sum of the square of its digits. If it loops endlessly in a cycle which does not include 1, then it is not a happy number.
//so we can use the same logic of slow fast pointer to detect the cycle in the sum


//here we just simply needs to find cycle is there or not in the form of 1 if there is a cycle and it is not 1 than it is not a happy number and if there is a cycle and it is 1 than it is a happy number