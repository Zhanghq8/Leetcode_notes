#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        unordered_map<char, int> data;
        for (int j = 0, i = -1; j < s.size(); j++) {
            if (data.count(s[j]) == 1) {
                i = max(i, data[s[j]]);
            }
            result = max(result, j - i);
            data[s[j]] = j;
        }
        return result;
    }
};