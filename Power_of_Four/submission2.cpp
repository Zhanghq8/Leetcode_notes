#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n > 0 && n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
    }
};

