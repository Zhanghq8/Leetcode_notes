#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) {
            return 0;
        }
        int right = s.size()-1;
        int cnt = 0;
        while (s[right] == ' ') {
            right--;
        }
        while (right >= 0 && s[right] != ' ') {
            right--;
            cnt++;
        }
        return cnt;
    }
};