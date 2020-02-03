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

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> dict = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string solution = "";
        helper(digits, 0, dict, solution, result);
        return result;
    }
private:
    void helper(string digits, int length, vector<string>& dict, string solution, vector<string>& result) {
        if (length == digits.size()) {
            result.push_back(solution);
            return;
        }
        for (char c : dict[digits[length] - '0']) {
            solution.push_back(c);
            helper(digits, length + 1, dict, solution, result);
            solution.pop_back();
        }
    }
};