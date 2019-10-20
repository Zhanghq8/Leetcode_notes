#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) {
            return image;
        }
        int color = image[sr][sc];
        dfs(image, sr, sc, color, newColor);
        return image;
    }
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int newColor) {
        if (sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size()) {
            return;
        }
        if (image[sr][sc] != color) {
            return;
        }
        image[sr][sc] = newColor;
        dfs(image, sr-1, sc, color, newColor);
        dfs(image, sr+1, sc, color, newColor);
        dfs(image, sr, sc-1, color, newColor);
        dfs(image, sr, sc+1, color, newColor);
    }
};
