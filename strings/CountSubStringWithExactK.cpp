// example 1:
// Input:
//  s = "pqpqs", k = 2  
// Output:
//  7  
// Explanation:
//   All substrings with exactly 2 distinct characters:  
// "pq", "pqp", "pqpq", "qp", "qpq", "pqs", "qs"  
// Total = 7.

// example 2:
//leetcode  : 992. Subarrays with K Different Integers
#include<iostream>
#include<unordered_map>
using namespace std;

int atmost(string s,int k){
    unordered_map<char,int> freq;  
    int count=0;
    int l=0;

    for(int r=0;r<s.size();r++){
        freq[s[r]]++;  

        while(freq.size() > k){   //map size always gives the size of distinct characters in the current window
            freq[s[l]]--;         
            if(freq[s[l]] == 0){
                freq.erase(s[l]);
            }
            l++;                  
        }

        count += (r - l + 1);     
    }
    return count;
}

int stringcount(string s,int k){
    return atmost(s,k) - atmost(s,k-1);
}

int main(){
    string s="pqpqs";
    int k=2;
    cout<<stringcount(s,k);  
}