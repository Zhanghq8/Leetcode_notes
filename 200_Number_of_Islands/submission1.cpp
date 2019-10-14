#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        if (grid.empty() == true || grid[0].empty() == true) {
            return result;
        }
        vector<vector<bool>> visited (grid.size(), vector<bool> (grid[0].size(), false));
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    helper(grid, visited, i, j);
                    result++;
                }
            }
        }
        return result;
    }
private:
    void helper(vector<vector<char>>& grid, vector<vector<bool>>& is_visted, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[x].size()) {
            return;
        }
        if (is_visted[x][y] == true) {
            return;
        }
        if (grid[x][y] == '0') {
            return;
        }
        is_visted[x][y] = true;
        helper(grid, is_visted, x-1, y);
        helper(grid, is_visted, x+1, y);
        helper(grid, is_visted, x, y-1);
        helper(grid, is_visted, x, y+1);
    }
};
