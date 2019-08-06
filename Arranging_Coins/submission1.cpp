#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 1) {
            return n;
        }
        long low = 1;
        long high = n;
        while (low < high) {
            long mid = low + (high - low)/2;
            long sum = (mid + 1) * mid / 2 ;
            if (sum > n) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low - 1;
    }
};