#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0;
        stack<int> S;
        S.push(-1);
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') {
                S.push(i);
            }
            else {
                S.pop();
                if (S.empty()) {
                    S.push(i);
                }
                else {
                    int length = i-S.top();
                    if (length > max) {
                        max = length;
                    }
                }
            }
        }
        return max;
    }
};