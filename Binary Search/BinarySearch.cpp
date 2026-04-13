// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

bool BinarySearch(vector<int>nums,int x){
    int n=nums.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==x){
            return true;
        }else if(nums[mid]>x){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return false;
}
int main() {
    vector<int>nums={3,4,6,7,9,12,16,17};
    int tag=6;
    bool ans=BinarySearch(nums,tag);
    if(ans==1)cout<<"the number is present";
    else cout<<"absent";

    return 0;
}


//recursive approach
// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

bool BinarySearch(vector<int>nums,int x,int low,int high){
    if(low>high) return false;
    int mid=(low+high)/2;
   if(nums[mid]==x) return true;
   else if(nums[mid]>x) return BinarySearch(nums,x,low,mid-1);
   else return BinarySearch(nums,x,mid+1,high);
   return false;
}
int main() {
    vector<int>nums={3,4,6,7,9,12,16,17};
    int tag=6;
    int n=nums.size();
    bool ans=BinarySearch(nums,tag,0,n-1);
    if(ans==1)cout<<"the number is present";
    else cout<<"absent";

    return 0;
}