//leetcode 874. Walking Robot Simulation

#include <iostream>
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        // store obstacles
        set<pair<int,int>> st;
        for(auto o : obstacles) {
            st.insert({o[0], o[1]});
        }

        // directions: North, East, South, West
        vector<pair<int,int>> dir = {
            {0,1}, {1,0}, {0,-1}, {-1,0}
        };

        int x = 0, y = 0;
        int d = 0; // start facing north
        int ans = 0;

        for(int cmd : commands) {

            // turn right
            if(cmd == -1) {
                d = (d + 1) % 4;
            }
            // turn left
            else if(cmd == -2) {
                d = (d + 3) % 4;
            }
            // move forward
            else {
                for(int i = 0; i < cmd; i++) {
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;

                    // stop if obstacle
                    if(st.count({nx, ny})) break;

                    x = nx;
                    y = ny;

                    ans = max(ans, x*x + y*y);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> commands = {4, -1, 3};
    vector<vector<int>> obstacles = {};
    cout << sol.robotSim(commands, obstacles) << endl; // Output: 25
    return 0;
}