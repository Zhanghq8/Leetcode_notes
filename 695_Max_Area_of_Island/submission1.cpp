#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = INT_MIN;
        vector<vector<bool>> visited{grid.size(), vector<bool>(grid[0].size(), false)};
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = 0;
                    dfs(grid, visited, i, j, area);
                    if (area > max_area) {
                        max_area = area;
                    }
                }
            }
        }
        return max_area == INT_MIN ? 0 : max_area;
    }
private:
    void dfs (vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& area) {
        if (x<0 || x>=grid.size() || y<0 || y>=grid[x].size() || visited[x][y] || !grid[x][y]) {
            return;
        }
        area++;
        visited[x][y] = true;
        dfs(grid, visited, x-1, y, area);
        dfs(grid, visited, x+1, y, area);
        dfs(grid, visited, x, y-1, area);
        dfs(grid, visited, x, y+1, area);
    }
};
