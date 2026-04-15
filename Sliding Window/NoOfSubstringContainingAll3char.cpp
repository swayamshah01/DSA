// leetcode : 1358

#include<iostream>
#include<vector>
using namespace std;

int numberOfSubstrings(string s) {
    int l = 0, n = s.size();
    int count = 0;
    vector<int> freq(3, 0);

    for(int r = 0; r < n; r++){
        freq[s[r] - 'a']++;

        while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
            count += (n - r);
            freq[s[l] - 'a']--;
            l++;
        }
    }
    return count;
}

int main(){
    string s = "abcabc";
    int ans = numberOfSubstrings(s);
    cout << ans;
}