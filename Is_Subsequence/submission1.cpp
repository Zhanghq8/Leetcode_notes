#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptrs = 0;
        int ptrt = 0;
        while (ptrs < s.size() && ptrt < t.size()) {
            if (s[ptrs] == t[ptrt]) {
                ptrs++;
                ptrt++;
            }
            else {
                ptrt++;
            }
        }
        if (ptrs >= s.size() && ptrt <= t.size()) {
            return true;
        }
        return false;
    }
};