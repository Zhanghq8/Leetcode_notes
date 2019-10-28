#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> memo;
        return iswordBreak(s, dict, memo);
    }
private:
    bool iswordBreak(string s, unordered_set<string>& dict, unordered_map<string, bool>& memo) {
        if (memo.count(s)) {
            return memo[s];
        }
        if (dict.find(s) != dict.end()) {
            memo[s] = true;
            return true;
        }
        for (int i=1; i<s.size(); i++) {
            string s_left = s.substr(0, i);
            string s_right = s.substr(i);
            if (iswordBreak(s_left, dict, memo) && dict.find(s_right) != dict.end()) {
                memo[s] = true;
                return true;
            }
        }
        memo[s] = false;
        return false;
    }
};