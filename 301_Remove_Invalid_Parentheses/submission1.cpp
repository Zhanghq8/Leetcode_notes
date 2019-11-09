#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        if (s.empty()) {
            return {""};
        }
        vector<string> result;
        int open = 0, close = 0;
        getInValid(s, open, close);
        int start = 0;
        dfs(start, open, close, s, result);
        return result;
    }
private:
    bool isValid(string str) {
        int count = 0;
        for (int i=0; i<str.size(); i++) {
            if (str[i] == '(') {
                count++;
            }
            else if (str[i] == ')') {
                count--;
            }
            if (count < 0) {
                return false;
            }
        }
        return count == 0;
    }
    void getInValid (string s, int& open, int& close) {
        for (int i=0; i<s.size(); i++) {
            if (s[i] == ')') {
                if (open == 0) {
                    close++;
                }
                else {
                    open--;
                }
            }
            else if (s[i] == '('){
                open++;
            }
        }
    }
    void dfs(int start, int open, int close, string str, vector<string>& result) {
        if (open == 0 && close == 0) {
            if (isValid(str)) {
                result.push_back(str);
                return;
            }
            return;
        }
        for (int i=start; i<str.size(); i++) {
            if (i != start && str[i] == str[i - 1]) {
                continue;
            }
            string cur = str;
            if (close > 0 && str[i] == ')') {
                str.erase(i,1);
                close--;
                dfs(i, open, close, str, result);
                close++;
                str = cur;
            }
            if (open > 0 && str[i] == '(') {
                str.erase(i,1);
                open--;
                dfs(i, open, close, str, result);
                open++;
                str = cur;
            }
        }
    }
};