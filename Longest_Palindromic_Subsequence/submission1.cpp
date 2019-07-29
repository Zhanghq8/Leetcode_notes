#include <iostream>
#include <string>

using namespace std;

// DP

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int> (s.size(), 0));
        for (int i=0; i<s.size(); i++) {
            dp[i][i] = 1;
        }
        int diff = 1, row = 0, col = 1;
        while (col - row <= s.size()) {
            row = 0;
            col = row + diff;
            while (col < s.size()) {
                if (s[row] == s[col]) {
                    dp[row][col] = dp[row+1][col-1] + 2;
                }
                else {
                    dp[row][col] = max(dp[row][col-1], dp[row+1][col]);
                }
                row++;
                col++;
            }
            diff++;
        }
        return dp[0][s.size()-1];
    }
};
