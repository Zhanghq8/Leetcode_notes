#include <iostream>
#include <string>

using namespace std;

// Bit manipulation

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0) {
            return false;
        }
        int temp = n & (n-1);
        if (n > 0 && temp == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};

