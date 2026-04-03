#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {2,3,4,5,6};

    vector<int> ans;

    int i = 0, j = 0;

    // Traverse both vectors
    while(i < v1.size() && j < v2.size()) {
        if(v1[i] < v2[j]) {
            if(ans.empty() || ans.back() != v1[i])
                ans.push_back(v1[i]);
            i++;
        }
        else if(v1[i] > v2[j]) {
            if(ans.empty() || ans.back() != v2[j])
                ans.push_back(v2[j]);
            j++;
        }
        else { // equal
            if(ans.empty() || ans.back() != v1[i])
                ans.push_back(v1[i]);
            i++;
            j++;
        }
    }

    // Remaining elements
    while(i < v1.size()) {
        if(ans.empty() || ans.back() != v1[i])
            ans.push_back(v1[i]);
        i++;
    }

    while(j < v2.size()) {
        if(ans.empty() || ans.back() != v2[j])
            ans.push_back(v2[j]);
        j++;
    }

    // Print result
    cout << "Union: ";
    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}