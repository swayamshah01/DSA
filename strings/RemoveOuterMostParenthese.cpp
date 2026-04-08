//leetcode 1021. Remove Outermost Parentheses

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result="";
        int count=0;
        for(char c : s){
            if(c=='('){
                if(count>0) result+=c;
                count++;
            }else{
                count--;
                if(count>0) result+=c;
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    string str="(()())(())";
    cout<<s.removeOuterParentheses(str)<<endl;
    return 0;
}