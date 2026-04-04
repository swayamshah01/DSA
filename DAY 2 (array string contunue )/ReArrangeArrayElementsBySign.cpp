#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;

        // Separate positives and negatives
        for(int x : nums){
            if(x > 0) pos.push_back(x);
            else neg.push_back(x);
        }

        vector<int> result;
        int i = 0, j = 0;

        // Alternate elements
        while(i < pos.size() && j < neg.size()){
            result.push_back(pos[i++]);
            result.push_back(neg[j++]);
        }

        return result;
    }
};



//without using extra space as even +1 and odd is +2 from start

class Solution2 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int posIndex = 0; // even index
        int negIndex = 1; // odd index

        for(int x : nums){
            if(x > 0){
                result[posIndex] = x;
                posIndex += 2;
            } else {
                result[negIndex] = x;
                negIndex += 2;
            }
        }

        return result;
    }
};