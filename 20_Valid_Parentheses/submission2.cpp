#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Vector

class Solution {
public:
    bool isValid(string s) {
        vector<char> temp; 
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                temp.push_back(s[i]);
            }
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (temp.empty() == true || (*temp.end() != '(' && s[i] == ')') || (*temp.end() != '[' && s[i] == ']') || (*temp.end() != '{' && s[i] == '}')) {
                    return false;
                }
                else {
                    temp.pop_back();
                }
            }
        }
        return temp.empty() ? true:false;
    }
};
