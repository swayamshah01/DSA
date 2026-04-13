// Binary Search in Rotated Sorted Array I
//33

#include <iostream>
#include<vector>
using namespace std;

int RotatedSearch(vector<int>nums,int x){
    int low=0,high=nums.size()-1;
    while(low<=high){
        int mid=low+((high-low)/2);
        if(nums[mid]==x) return mid;
        //left half sorted
        else if(nums[low]<=nums[mid]){
            if(nums[low]<=x && x<=nums[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
            //right half sorted
        }else{
            if(nums[mid]<=x && x<=nums[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int>nums={4,5,6,7,0,1,2};
    int x=0;
    int ans=RotatedSearch(nums,x);
    cout<<ans;
    
    return 0;
}