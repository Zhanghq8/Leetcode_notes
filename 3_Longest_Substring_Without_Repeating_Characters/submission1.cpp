#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 1 || s.empty() == true) {
            return s.size();
        }
        int result = 0;
        int start = 0;
        int end = 0;
        map<char, int> m;
        while (end < s.size()) {
            if (m.find(s[end]) != m.end()) {
                if (m[s[end]] <start) {
                    m[s[end]] = end;
                }
                else {
                    result = max(end-start, result);
                    start = m[s[end]] + 1; 
                    m[s[end]] = end;
                }
            }
            else {
                m[s[end]] = end;
            }
            end++;
        }
        result = max(end-start, result);
        return result;
    }
};