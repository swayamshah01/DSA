// leetcode : 03

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlength = 0;
        int len=0;
        unordered_map<char,int>mpp;
        int l=0;
        for(int r=0;r<n;r++){
            mpp[s[r]]++;
            while(mpp[s[r]]>1){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            maxlength=max(maxlength,r-l+1);
        }
        return maxlength;
    }
};