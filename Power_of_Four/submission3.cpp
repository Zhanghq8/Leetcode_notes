#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        double temp = log10(n)/log10(4);
        if (temp == (int)temp && n > 0) {
            return true;
        }
        return false;
    }
};

