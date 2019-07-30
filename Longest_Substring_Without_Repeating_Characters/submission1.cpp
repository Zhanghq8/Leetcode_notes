#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0;
        int max_length = 0;
        set<char> char_set;
        while (end < s.size()) {
            if (char_set.find(s[end]) != char_set.end()) {
                while (s[start] != s[end]) {
                    char_set.erase(s[start]);
                    start++;
                }
                char_set.erase(s[start]);
                start++;
            }
            char_set.insert(s[end]);
            if (max_length < char_set.size()) {
                max_length = char_set.size();
            }
            end++;
        }
        return max_length;        
    }
};
