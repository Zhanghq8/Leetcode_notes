#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> sHash;
        unordered_map<char, int> tHash;
        for (int i = 0; i < s.size(); i++) {
            if (sHash[s[i]] != tHash[t[i]]) {
                return false;
            }
            sHash[s[i]] = i + 1;
            tHash[t[i]] = i + 1;
        }
        return true;
    }
};