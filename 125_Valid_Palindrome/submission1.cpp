#include <iostream>
#include <string>

using namespace std;

// ASCII
// 48-57 -> 0-9
// 32 -> space
// 65-90 -> A-Z
// 97-122 -> a-z


class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (!isAlpha(s[left])) {
                left++;
            }
            else if (!isAlpha(s[right])) {
                right--;
            }
            else if ((s[left]+32-'a')%32 != (s[right]+32-'a')%32) {
                return false;
            }
            else {
                left++;
                right--;
            }
        }
        return true;
    }
private:
    bool isAlpha (char ele) {
        if (ele >= '0' && ele <= '9') {
            return true;
        }
        if (ele >= 'a' && ele <= 'z') {
            return true;
        }
        if (ele >= 'A' && ele <= 'Z') {
            return true;
        }
        return false;
    }
};