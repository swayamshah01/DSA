#include<iostream>
#include<vector>
#include<map>
using namespace std;

int missing(vector<int> v, int n){
    map<int,int> mpp;

    // Initialize all values
    for(int i = 1; i <= n+1; i++){
        mpp[i] = 0;
    }

    // Mark present elements
    for(int i = 0; i < n; i++){
        mpp[v[i]] = 1;
    }

    // Now use it.second
    for(auto it : mpp){
        if(it.second == 0){
            return it.first;
        }
    }

    return -1;
}

int main(){
    vector<int> v = {8,2,4,5,3,7,1};
    int n = v.size();

    cout << missing(v, n);
}