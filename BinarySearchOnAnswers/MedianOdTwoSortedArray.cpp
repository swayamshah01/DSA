//leetcode: 4. Median of Two Sorted Arrays
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
#include<iostream>
#include<vector>
using namespace std;

double median(vector<int> a, vector<int> b) {
    int n = a.size() + b.size();
    int idx2 = n / 2;
    int idx1 = idx2 - 1;
    int i = 0, j = 0;
    int cnt = 0;
    int el1 = -1, el2 = -1;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            if (cnt == idx1) el1 = a[i];
            if (cnt == idx2) el2 = a[i];
            i++;
        } else {
            if (cnt == idx1) el1 = b[j];
            if (cnt == idx2) el2 = b[j];
            j++;
        }
        cnt++;
    }

    while (i < a.size()) {
        if (cnt == idx1) el1 = a[i];
        if (cnt == idx2) el2 = a[i];
        i++;
        cnt++;
    }

    while (j < b.size()) {
    
        if (cnt == idx1) el1 = b[j];
        if (cnt == idx2) el2 = b[j];
        j++;
        cnt++;
    }

    if (n % 2 == 0) return (double)(el1 + el2) / 2.0;
    else return (double)el2;
}

int main() {
    vector<int> a = {1, 2};
    vector<int> b = {3, 4};
    double ans = median(a, b);
    cout << ans; 
    return 0;
}