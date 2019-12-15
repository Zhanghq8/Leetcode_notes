#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        vector<vector<int>> dirs{{-1,0}, {1,0}, {0,-1}, {0,1}};
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    int area = 1;
                    queue<pair<int, int>> Q;
                    Q.push({i,j});
                    while (!Q.empty()) {
                        auto cur = Q.front();
                        grid[cur.first][cur.second] = 2;
                        Q.pop();
                        for (auto n : dirs) {
                            int x = cur.first + n[0];
                            int y = cur.second + n[1];
                            if (x<0 || x>=grid.size() || y<0 || y>=grid[x].size() 
                                || grid[x][y] != 1) {
                                continue;
                            }
                            area++;
                            grid[x][y] = 2;
                            Q.push({x,y});
                        }
                    }
                    max_area = max(area, max_area);
                }
            }
        }
        return max_area;
    }
};
