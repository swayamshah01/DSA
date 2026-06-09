//Recursive Binary Exponentiation
//divide and conquer approach

// x^n = (x^(n/2))^2 if n is even
// x^n = x * (x^(n/2))^2 if n is odd


#include <iostream>
using namespace std;

class Solution {
public:
     long long MOD = 1e9 + 7;
     long long power(long long x, long long n) {
        if (n == 0) return 1;

        long long half = power(x, n / 2);
        long long result = (half * half) % MOD;

        if (n % 2 == 1) result = (result * x) % MOD;

        return result;
    }

    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;
        long long ans= (power(5,even)*power(4,odd))%MOD;

        return int(ans);
    }
};

int main() {
    Solution s;
    long long n = 4;
    cout << s.countGoodNumbers(n) << endl; 
    return 0;
}
//(choices for type A)^(count of A) * (choices for type B)^(count of B)
// for n = 4 
0 1 2 3 4
o e o e o

even should be even : 0 2 4 6 8  //choices for type A == 5 
odd should be prime : 2 3 5 7   //choices for type B == 4

even = (n + 1) / 2
odd = n / 2


🔑 Mental Model (THIS is gold)

Instead of memorizing formula, ask:

👉 “At each position, how many choices do I have?”

Then:

multiply all choices

If many positions have same choices → use power