#include <iostream>
#include <stack>
#include <string>

using namespace std;

// DFS

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty() == true) {
            return {};
        }
        vector<string> result;
        vector<string> dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        helper(result, "", dict, digits, 0);
        return result;
    }
private:
    void helper(vector<string>& result, string solution, vector<string>& dict, string digits, int level) {
        if (level == digits.size()) {
            result.push_back(solution);
            return;
        }
        string temp = dict[digits[level] - '2'];
        for (int i=0; i<temp.size(); i++) {
            helper(result, solution+temp[i], dict, digits, level+1);
        }
    }
};