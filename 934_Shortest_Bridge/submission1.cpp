#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        vector<vector<int>> dirs{{-1,0}, {1,0}, {0,-1}, {0,1}};
        int result = 0;
        queue<pair<int, int>> coords;
        for (int i=0; i<A.size(); i++) {
            for (int j=0; j<A[i].size(); j++) {
                if (A[i][j] == 1) {
                    dfs_findIsland(A, i, j, coords);
                    i = A.size()-1;
                    j = A[i].size()-1;
                }
            }
        }
        while (!coords.empty()) {
            int length = coords.size();
            while (length > 0) {
                pair<int, int> coord = coords.front();
                coords.pop();
                for (auto cur : dirs) {
                    int x = cur[0] + coord.first;
                    int y = cur[1] + coord.second;
                    if (x<0 || x>=A.size() || y<0 || y>=A[x].size()) {
                        continue;
                    }
                    if (A[x][y] == -1) {
                        continue;
                    }
                    if (A[x][y] == 1) {
                        return result;
                    }
                    A[x][y] = -1;
                    coords.push({x,y});
                }
                length--; 
            }
            result++;
        }
        return -1;
    }
private:
    void dfs_findIsland (vector<vector<int>>& A, int x, int y, queue<pair<int, int>>& coords) {
        if (x < 0 || x >= A.size() || y < 0 || y >= A[x].size() || A[x][y] == -1 || A[x][y] == 0) {
            return;
        }
        A[x][y] = -1;
        coords.push({x,y});
        dfs_findIsland(A, x-1, y, coords);
        dfs_findIsland(A, x+1, y, coords);
        dfs_findIsland(A, x, y-1, coords);
        dfs_findIsland(A, x, y+1, coords);
    }
};