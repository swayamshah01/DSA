class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        for(char c : s) {
            mpp[c]++;
        }

        // Use a priority queue to store {frequency, character}
        // This automatically keeps the highest frequency at the top
        priority_queue<pair<int, char>> pq;
        for(auto it : mpp) {
            pq.push({it.second, it.first});
        }

        string result = "";
        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            
            // Append the character 'frequency' number of times
            result.append(temp.first, temp.second);
        }
        
        return result;
    }
};