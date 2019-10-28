#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if (strs.empty()) {
            return result;
        }
        for (int i=1; i<=strs[0].size(); i++) {
            string sub_str = strs[0].substr(0, i);
            for (int i=0; i<strs.size(); i++) {
                if (sub_str.size() > strs[i].size()) {
                    break;
                }
                if (strs[i].find(sub_str) == 0) {
                    if (i == strs.size()-1) {
                        result = sub_str;
                    }
                }
                else {
                    break;
                }
            }
        }
        return result;
    }
};