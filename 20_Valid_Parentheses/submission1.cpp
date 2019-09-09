#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Stack

class Solution {
public:
    bool isValid(string s) {
        stack<char> S; 
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                S.push(s[i]);
            }
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (S.empty() == true || (S.top() != '(' && s[i] == ')') || (S.top() != '[' && s[i] == ']') || (S.top() != '{' && s[i] == '}')) {
                    return false;
                }
                else {
                    S.pop();
                }
            }
        }
        return S.empty() ? true:false;
    }
};
