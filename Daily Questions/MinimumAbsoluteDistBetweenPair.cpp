//leetcode 3761

#include <iostream>
#include <vector>
#include<unordered_map>
#include<climits>
using namespace std;

int rev(int n){
    int rev=0;
    while(n>0){
        rev=rev*10+n%10;
        n=n/10;
    }
    return rev;
}

int minMirrorPairDistance(vector<int>nums){
    unordered_map<int,int>mpp;
    int mindist=INT_MAX;
    for(int i=0;i<nums.size();i++){
        int x = nums[i];
        if(mpp.find(x)!=mpp.end()){
            int dist=i-mpp[x];
            mindist=min(mindist,dist);
        }
        int revx=rev(x);
        mpp[revx]=i;
    }
    return mindist==INT_MAX? -1 : mindist;
}

int main(){
    vector<int> nums = {12, 21, 45, 33, 54};
    int ans=minMirrorPairDistance(nums);
    cout<<ans;
}

//we cannot store the rev and check wirth rev before as it can  falsely handle the cases like [120,12]
//120 rev 21 in map find not present false
//so first we check with the original number and than we store the rev in the map so that we can handle the cases like [120,12] as well