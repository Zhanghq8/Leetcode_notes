#include <iostream>
#include <string>

using namespace std;

// if s[i-1] and s[i-1][i-2] is invalid -> 0
// if s[i-1] and s[i-1][i-2] is valid -> dp[i-1]+dp[i-2]
// if s[i-1] is valid -> +dp[i-1]
// if s[i-1][i-2] is valid -> +dp[i-2]

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for (int i=1; i<dp.size(); i++) {
            if (s[i-1] == '0' && (s.substr(i-2, 2) < "10" && s.substr(i-2, 2) > "26")) {
                return 0;
            }
            else if (i>1 && s[i-1] != '0' && (s.substr(i-2, 2) >= "10" && s.substr(i-2, 2) <= "26")) {
                dp[i] = dp[i-1] + dp[i-2];
            }
            else if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }
            else if (s.substr(i-2, 2) >= "10" && s.substr(i-2, 2) <= "26") {
                dp[i] += dp[i-2];
            }
        }
        return dp[s.size()];
    }
};