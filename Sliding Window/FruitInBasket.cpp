#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int fruitinBasket(vector<int>nums,int n){
    int maxlen=0;
    for(int i=0;i<n;i++){
        set<int>st;
        for(int j=i;j<n;j++){
            st.insert(nums[j]);
            if(st.size()>2){
                break;
            }else{
                maxlen=max(maxlen,j-i+1);
            }
        }
    }
    return maxlen;
}


int main(){
    vector<int>nums={3,3,3,1,2,1,1,2,3,3,4};
    int n = nums.size();
    int ans=fruitinBasket(nums,n);
    cout<<ans;
}


#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int fruitinBasket(vector<int>nums,int n){
    int maxlen=0,l=0;
    unordered_map<int,int>freq;
    for(int r=0;r<n;r++){
        freq[nums[r]]++;
        while(freq.size()>2){
            freq[nums[l]]--;
            if(freq[nums[l]]==0)freq.erase(nums[l]);
            l++;
        }
        maxlen=max(maxlen,r-l+1);
    }
    return maxlen;
}



int main(){
    vector<int>nums={3,3,3,1,2,1,1,2,3,3,4};
    int n = nums.size();
    int ans=fruitinBasket(nums,n);
    cout<<ans;
}