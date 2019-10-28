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
        int left = 1;
        int right = strs[0].size()+1;
        while (left < right) {
            int mid = left + (right - left)/2;
            string sub_str = strs[0].substr(0, mid);
            for(int i=0; i<strs.size(); i++) {
                if (strs[i].find(sub_str) == 0) {
                    if (i == strs.size()-1) {
                        result = sub_str;
                        left = mid+1;
                    }
                }
                else {
                    right = mid;
                    break;
                }
            }
        }
        return result;
    }
};