#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> repeatedTimes;
        for (int i = 0; i < s.size(); i++) {
            repeatedTimes[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (repeatedTimes[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};