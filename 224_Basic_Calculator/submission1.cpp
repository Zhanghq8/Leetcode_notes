#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int sign = 1;
        int result = 0;
        stack<int> S;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '.') {
                continue;
            }
            else if (s[i] >= '0') {
                int num = 0;
                while (s[i] >= '0' && i < s.size()) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                result += sign * num;
            }
            else if (s[i] == '+') {
                sign = 1;
            }
            else if (s[i] == '-') {
                sign = -1;
            }
            else if (s[i] == '(') {
                S.push(result);
                S.push(sign);
                result = 0;
                sign = 1;
            }
            else if (s[i] == ')') {
                result *= S.top();
                S.pop();
                result += S.top();
                S.pop();
            }
        }
        return result;
    }
};