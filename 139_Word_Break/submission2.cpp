#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dic(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i=0; i<s.size()+1; i++) {
            for (int j=0; j<i; j++) {
                if (dp[j] && dic.count(s.substr(j, i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};