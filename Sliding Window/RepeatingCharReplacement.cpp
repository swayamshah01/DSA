#include<iostream>
#include<vector>
using namespace std;

int characterReplacement(string s, int k) {
    int n = s.size();
    int maxLen = 0;
    for(int i = 0; i < n; i++) {

        vector<int> freq(26, 0); 
        int maxFreq = 0;
        for(int j = i; j < n; j++) {

            freq[s[j] - 'A']++;  
            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            int len = j - i + 1;
            if(len - maxFreq <= k) {
                maxLen = max(maxLen, len);
            }
        }
    }

    return maxLen;
}

int main() {
    string s = "AABABBA";
    int k = 1;

    cout << characterReplacement(s, k);
}



#include<iostream>
#include<vector>
using namespace std;

int characterReplacement(string s, int k) {
    int n = s.size();
    int maxlen = 0;
    int l=0;
    int maxfreq=0;
    vector<int>freq(26,0);
    for(int r=0;r<n;r++){
        freq[s[r]-'A']++;
        maxfreq=max(maxfreq,freq[s[r]-'A']);
        while((r-l+1)-maxfreq>k){
            freq[s[l]-'A']--;
            l++;
        }
        maxlen=max(maxlen,r-l+1);
    }

return maxlen;
}

int main() {
    string s = "AABABBA";
    int k = 1;

    cout << characterReplacement(s, k);
}