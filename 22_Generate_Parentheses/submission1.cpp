#include <iostream>
#include <stack>
#include <string>

using namespace std;

// DFS

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        helper(result, "", n, n);
        return result;
    }
private:
    void helper(vector<string>& result, string solution, int left, int right) {
        if (left > right) {
            return;
        }
        if (left == 0 && right == 0) {
            result.push_back(solution);
        }
        else {
            if (left > 0) {
                helper(result, solution + '(', left-1, right);
            }
            if (right > 0) {
                helper(result, solution + ')', left, right-1);
            }
        }
    }
};