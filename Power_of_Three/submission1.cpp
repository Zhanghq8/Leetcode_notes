#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        double temp = n;
        while (temp >= 3) {
            if ((int)temp % 3 != 0) {
                return false;
            }
            temp = temp / 3.0;
            if ((int)temp == temp && temp == 1) {
                return true;
            }
        }
        return false;
    }
};

