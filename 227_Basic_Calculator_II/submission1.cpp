#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int num = 0;
        char op = '+';
        stack<int> S;
        for (int i=0; i<s.size(); i++) {
            if (s[i] >= '0') {
                num = num*10 + (s[i] - '0');
            }
            if ((s[i] < '0' && s[i] != ' ') || i == s.size()-1) {
                if (op == '+') {
                    S.push(num);
                }
                else if (op == '-') {
                    S.push(-num);
                }
                else if (op == '*' || op == '/') {
                    int temp = 0;
                    if (op == '*') {
                        temp = S.top() * num;
                    }
                    else {
                        temp = S.top() / num;
                    }
                    S.pop();
                    S.push(temp);
                }
                op = s[i];
                num = 0;
            }
        }
        while (!S.empty()) {
            result += S.top();
            S.pop();
        }
        return result;
    }
};