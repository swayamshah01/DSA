#include <iostream>
using namespace std;

int findsquare(int x)
{
    int low = 0, high = x;
    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int sq = mid * mid;

        if (sq == x)
            return mid;
        else if (sq < x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int x = 28;
    int ans = findsquare(x);
    cout << ans;
    return 0;
}