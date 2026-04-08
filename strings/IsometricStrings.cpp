// class Solution {
// public:
//     int duplicate(string s){
//         int freq[256]={0};
//         int count=0;
//         for(char c : s){
//             if(freq[c]!=0){
//                 count++;
//             }else{
//                 freq[c]++;
//             }
//         }
//         return count;
//     }
//     bool isIsomorphic(string s, string t) {
//         if(s.length()!=t.length()) return false;
//         if(duplicate(s)!=duplicate(t))return false ;
//         else return true;
//     }
// };
//this is basic logic and it will clear some cases but will fail in extreme cases like "ab" and "aa" as both have 1 duplicate but they are not isomorphic so we need to check the mapping of characters as well

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;

        for(int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // check s -> t mapping
            if(mapST.count(c1)) {
                if(mapST[c1] != c2) return false;
            } else {
                mapST[c1] = c2;
            }

            // check t -> s mapping
            if(mapTS.count(c2)) {
                if(mapTS[c2] != c1) return false;
            } else {
                mapTS[c2] = c1;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    string str1 = "flower";
    string str2 = "flow";
    cout << s.isIsomorphic(str1, str2) << endl; // Output should be 1 (true)
    return 0;
}
