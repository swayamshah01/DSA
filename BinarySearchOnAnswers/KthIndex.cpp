#include<iostream>
#include<vector>
using namespace std;

int median(vector<int> a, vector<int> b,int k) {
    int n = a.size() + b.size();
    int i = 0, j = 0;
    int cnt = 0;
    int el = -1;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            if (cnt == k) el = a[i];
            i++;
        } else {
            // FIX: Use b[j] here, not a[j]
            if (cnt == k) el = b[j];
            j++;
        }
        cnt++;
    }

    while (i < a.size()) {
        if (cnt == k) el = a[i];
        i++;
        cnt++;
    }

    while (j < b.size()) {
        if (cnt == k) el = b[j];
        j++;
        cnt++;
    }

   return el-1;
}

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int ans = median(a, b,5);
    cout << ans; 
    return 0;
}