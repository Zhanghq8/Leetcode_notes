#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int left = 0;
        int right = n;
        while (left < right) {
            long mid = left + (right - left) / 2;
            long sum = mid * (mid + 1) / 2;
            if (sum == n) {
                return mid;
            } else if (sum < n) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return n <= 1 ? n : right - 1;
    }
};