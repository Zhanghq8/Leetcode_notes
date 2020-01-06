#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        vector<vector<bool>> dp (s.size()+1, vector<bool> (p.size()+1, false));
        dp[0][0] = true;
        for (int i = 1; i < p.size()+1; i++) {
            if (p[i-1] == '*') {
                dp[0][i] = dp[0][i-1];
            }
        }
        for (int i = 1; i < s.size()+1; i++) {
            for (int j = 1; j < p.size()+1; j++) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                } else {
                    if (dp[i-1][j-1]) {
                        dp[i][j] = s[i-1] == p[j-1] || p[j-1] == '?';
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};