#include <iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int consecutive(vector<int>nums,int n){
    unordered_set<int>st(nums.begin(),nums.end());
    int longest=0;
    for(int num : st){
        if(st.find(num-1)!=st.end()){
            int curr_count=1;
            int curr_element=num;
            while(st.find(curr_element)!=st.end()){
                curr_count++;
                curr_element++;
            }
            longest=max(curr_count,longest);
        }
    }
    return longest;
}

int main() {
    vector<int>nums={100,4,200,1,2,3};
    int n=nums.size();
    int ans=consecutive(nums,n);
    cout<<ans;
    
    return 0;
}


//approach

// take a number
// check if the number-1 is present in the set or not
// if it is present then we will not consider that number as the starting point of the sequence
// if it is not present then we will consider that number as the starting point of the sequence
// then we will keep on checking for the next number in the sequence until we find a number which is not present in the set
// we will keep track of the count of the current sequence and update the longest sequence count if the current sequence count is greater than the longest sequence count
