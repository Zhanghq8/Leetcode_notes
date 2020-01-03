#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) {
            return s;
        }
        int start = 0;
        int length = 0;
        for (int i=0; i<s.size(); i++) {
            getLength(s, i, i, length, start);
            getLength(s, i, i+1, length, start);
        }
        return s.substr(start, length);
    }
private:
    void getLength(string s, int left, int right, int& length, int& start) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        if (right - left - 1 > length) {
            length = right - left - 1;
            start = left+1;
        }
    }
};
