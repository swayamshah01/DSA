class Solution {
public:
    int maxDepth(string s) {
        int len=0;
        int maxlen=0;
        for(char c : s){
            if(c=='(') {
                len++;
            maxlen=max(len,maxlen);
            }
            else if (c==')')len--;
        }
        return maxlen;
    }
};