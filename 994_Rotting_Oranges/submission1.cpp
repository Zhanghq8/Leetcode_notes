#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> Q;
        int minMins = 0;
        int numFresh = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    Q.push({i,j});
                }
                if (grid[i][j] == 1) {
                    numFresh++;
                }
            }
        }
        vector<vector<int>> dirs{{0,-1}, {0,1},{-1,0},{1,0}};
        while (!Q.empty() && numFresh) {
            int queueSize = Q.size();
            minMins++;
            while (queueSize > 0) {
                int row = Q.front().first;
                int col = Q.front().second;
                Q.pop();
                for (int i=0; i<dirs.size(); i++) {
                    int newRow = row + dirs[i][0];
                    int newCol = col + dirs[i][1];
                    if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size()) {
                        continue;
                    }
                    if (grid[newRow][newCol] == 2 || grid[newRow][newCol] == 0) {
                        continue;
                    }
                    grid[newRow][newCol] = 2;
                    Q.push({newRow,newCol});
                    numFresh--;
                }
                queueSize--;  
            }
        }
        return numFresh == 0 ? minMins : -1;
    }
};