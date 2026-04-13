#include <iostream>
using namespace std;

// Naive power function: computes mid^n
long long power(int mid, int n)
{
    long long ans = 1;

    for (int i = 0; i < n; i++)
    {
        ans = ans * mid;
    }

    return ans;
}

// Function to find Nth root of m
int NthRoot(int n, int m)
{
    int low = 1, high = m;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        long long val = power(mid, n);

        if (val == m)
            return mid;
        else if (val < m)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // if no integer root exists
}

int main()
{
    int n = 3;   // root
    int m = 27;  // number

    int ans = NthRoot(n, m);

    cout << ans << endl;  // Output: 3

    return 0;
}