#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        col = vector<bool> (n, false);
        diag = vector<bool> (2*n-1, false);
        o_diag = vector<bool> (2*n-1, false);
        board = vector<string> (n, string(n, '.'));
        dfs(result, n, 0);
        return result;  
    }
private:
    vector<bool> col;
    vector<bool> diag;
    vector<bool> o_diag;
    vector<string> board;
    
    bool isValid (int x, int y, int n) {
        return !col[y] && !diag[y-x+n-1] && !o_diag[x+y];
    }
    
    void updateBoard (int x, int y, int n, bool isPut) {
        board[x][y] = (isPut == true) ? 'Q' : '.';
        col[y] = isPut;
        diag[y-x+n-1] = isPut;
        o_diag[x+y] = isPut;
    }
    
    void dfs(vector<vector<string>>& result, int n, int x) {
        if (x == n) {
            result.emplace_back(board);
            return;
        }
        for (int i=0; i<n; i++) {
            if (!isValid(x, i, n)) {
                continue;
            }
            updateBoard(x, i, n, true);
            dfs(result, n, x+1);
            updateBoard(x, i, n, false);
        }
    }
    
};