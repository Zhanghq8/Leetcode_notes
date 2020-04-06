#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n <= 2) {
            return n == 0 ? 0 : 1;
        }
        int pre1 = 0;
        int pre2 = 1;
        int pre3 = 1;
        int sum = 0;
        for (int i = 3; i < n + 1; i++) {
            sum = pre1 + pre2 + pre3;
            pre1 = pre2;
            pre2 = pre3;
            pre3 = sum;
        }  
        return sum;
    }
};