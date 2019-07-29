#include <iostream>
#include <string>

using namespace std;

// DP

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int result = 0;
        vector<int> dp(nums.size()+1, 1);
        for (int i=1; i<nums.size()+1; i++) {
            for (int j=1; j<i; j++) {
                if (nums[j-1] < nums[i-1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > result) {
                result = dp[i];
            }
        }
        return result;
    }
};
