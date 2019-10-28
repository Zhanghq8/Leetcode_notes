#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> output;
        dfs(s, 0, result, output);
        return result;
    }
private:
    void dfs(string s, int start, vector<vector<string>>& result, vector<string>& output ) {
        if (start >= s.size()) {
            result.emplace_back(output);
            return;
        }
        for (int i=start; i<s.size(); i++) {
            string sub_str = s.substr(start, i-start+1);
            if (!isPalindrome(sub_str)) {
                continue;
            }
            output.emplace_back(sub_str);
            dfs(s, i+1, result, output);
            output.pop_back();
        }
    }
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        int left = 0, right = s.size()-1;
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};