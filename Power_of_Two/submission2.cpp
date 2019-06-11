#include <iostream>
#include <string>

using namespace std;

// log2

class Solution {
public:
    bool isPowerOfTwo(int n) {
        double temp = log2(n);
        if ((int)temp == temp) {
            return true;
        }
        else {
            return false;
        }
    }
};

