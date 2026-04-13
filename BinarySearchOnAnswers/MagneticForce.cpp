// In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

// Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

// Given the integer array position and the integer m. Return the required force.

 

// Example 1:


// Input: position = [1,2,3,4,7], m = 3
// Output: 3
// Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.

//leetcode 1552. Magnetic Force Between Two Balls

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    bool isPossible(vector<int> nums,int no_of_balls,int min_dist){
        int cntball=1;
        int n=nums.size();
        int lastBall=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]-lastBall>=min_dist){
                cntball++;
                lastBall=nums[i];
            }
        }
        if(cntball>=no_of_balls) return true;
        else return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=0;
        int high=*max_element(position.begin(),position.end());
        while(low<=high){
            int mid=low+((high-low)/2);
            if(isPossible(position,m,mid)==true) {
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return high;
    }


int main(){
    vector<int>position={1,2,3,4,7};
    int m=3;
;
    int ans=maxDistance(position,m);
    cout<<ans;
}