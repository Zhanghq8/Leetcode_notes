#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2) {
            return false;
        }
        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int> (target + 1, false));
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i < target + 1; i++) {
            dp[0][i] = nums[0] == i;
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j < target + 1; j++) {
                if (nums[i] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }   
            }
        }
        return dp.back().back();
    }
};