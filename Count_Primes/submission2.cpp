#include <iostream>
#include <string>

using namespace std;

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
        for (int i=2; i*i <= num; i++) {
            if (num%i == 0) {
                return false;
            }
        }
        return true;
    }
};

