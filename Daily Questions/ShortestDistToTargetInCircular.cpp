//leetcode 2515. Minimum Distance to Target Element in a Circular Array

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int dist=0,mindist=INT_MAX,diff=0;
        int n=words.size();
        for(int i=0;i<words.size();i++){
            if(words[i]==target){
                diff=abs(i-startIndex);
                dist=min(diff,n-diff);
                mindist=min(dist,mindist);
            }
        }
        if(mindist==INT_MAX) return -1;
        else return mindist;
    }
};
int main(){
    Solution s;
    vector<string> words={"hello","i","am","leetcode","hello"};
    string target="hello";
    int startIndex=1;
    cout<<s.closestTarget(words,target,startIndex);
}