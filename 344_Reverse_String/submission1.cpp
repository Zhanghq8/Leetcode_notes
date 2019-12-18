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
        int left = 0;
        int right = s.size()-1;
        while (left <= right) {
            helper(s[left], s[right]);
            left++;
            right--;
        }
    }
private:
    void helper(char& a, char& b) {
        char temp = a;
        a = b;
        b = temp;
    }
};