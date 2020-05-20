#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            double midD = static_cast<double> (mid);
            if (num / midD == midD) {
                return true;
            } else if (num / midD > midD) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};