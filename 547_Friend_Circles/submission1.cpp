#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int result = 0;
        vector<bool> visited(M.size(), false);
        for (int i=0; i<M.size(); i++) {
            if (visited[i]) {
                continue;
            }
            dfs(M, visited, i);
            result++;
        }
        return result;
    }
private:
    void dfs(vector<vector<int>>& M, vector<bool>& visited, int x) {
        if (visited[x]) {
            return;
        }
        visited[x] = 1;
        for (int i=0; i<M.size(); i++) {
            if (M[x][i] && !visited[i]) {
                dfs(M, visited, i);
            }
        }
    }
};