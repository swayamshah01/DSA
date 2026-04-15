//leetcode : 1614. Maximum Nesting Depth of the Parentheses
#include <iostream>
#include <string>
using namespace std;
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
int main(){
    Solution s;
    string str="(1+(2*3)+((8)/4))+1";
    cout<<s.maxDepth(str)<<endl;
    return 0;
}