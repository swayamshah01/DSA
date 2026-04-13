//leetcode : 774. Minimize Max Distance to Gas Station
// You are given an array stations that represents the positions of the gas stations along a horizontal number line, and an integer k. You should add k new gas stations so that the maximum distance between adjacent gas stations is minimized. Return the smallest possible value of this maximum distance. Answers within 10-6 of the actual answer will be accepted.

//very very imp


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

long double minmaxdist(vector<int> nums, int k) {
    int n = nums.size();
    priority_queue<pair<long double, int>> pq;
    vector<int> gasStationAllocated(n - 1, 0);

    for(int i = 0; i < n - 1; i++) {
        pq.push({(long double)nums[i+1] - nums[i], i});
    }

    // Loop exactly k times
    for(int i = 0; i < k; i++) {
        auto tp = pq.top();
        pq.pop();
        
        int secidx = tp.second;
        gasStationAllocated[secidx]++;
        
        long double inidiff = (long double)nums[secidx+1] - nums[secidx];
        // FIX: Parentheses around the denominator
        long double newseclen = inidiff / (long double)(gasStationAllocated[secidx] + 1);
        
        pq.push({newseclen, secidx});
    }
    return pq.top().first;
}

int main() {
    vector<int> nums = {1, 13, 17, 23};
    int k = 5;
    // Store as long double to see the precision
    long double ans = minmaxdist(nums, k);
    cout << ans; 
    return 0;
}

//this is done using priority queue, we can also do this using binary search on answer, but that will be more complex and less efficient than this approach. This approach is more intuitive and easier to implement. We are always adding a gas station in the largest gap, so we are minimizing the maximum distance between adjacent gas stations.