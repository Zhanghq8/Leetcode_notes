#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) {
            return;
        }
        helper(s, 0, s.size()-1);
    }
private:
    void helper(vector<char>& s, int start, int end) {
        if (start >= end) {
            return;
        }
        swap(s[start], s[end]);
        helper(s, start+1, end-1);
    }
    void swap(char& a, char& b) {
        char temp = a;
        a = b;
        b = temp;
    }
};
