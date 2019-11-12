#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> dirs{{-1,0}, {1,0}, {0,-1}, {0,1}};
        queue<pair<int, int>> Q;
        int oriColor = image[sr][sc];
        if (oriColor == newColor) {
            return image;
        }
        Q.push({sr,sc});
        while (!Q.empty()) {
            int length = Q.size();
            while (length > 0) {
                auto cur = Q.front();
                Q.pop();
                image[cur.first][cur.second] = newColor;
                for (auto dir : dirs) {
                    int x = cur.first + dir[0];
                    int y = cur.second + dir[1];
                    if (x<0 || x>=image.size() || y<0 || y>=image[x].size() || image[x][y] != oriColor) {
                        continue;
                    }
                    Q.push({x,y});
                }
                length--;
            }
        }
        return image;
    }
};
