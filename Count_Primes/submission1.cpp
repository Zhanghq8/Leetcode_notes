#include <iostream>
#include <string>

using namespace std;

// TLE

class Solution {
public:
    int countPrimes(int n) {
        int result = 0;
        if (n == 0) {
            return result;
        }
        vector<int> dp(n, 0);
        for (int i=2; i<dp.size(); i++) {
            if (helper(i) == true) {
                dp[i] = dp[i-1] + 1;
            }
            else {
                dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
private:
    bool helper(int num) {
        if (num == 2) {
            return true;
        }
        int temp = 2;
        while (temp < num) {
            if (num%temp == 0) {
                return false;
            }
            temp++;
        }
        return true;
    }
};

