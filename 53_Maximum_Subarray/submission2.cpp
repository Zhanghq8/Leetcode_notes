#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        int result = INT_MIN;
        for (int i = 1; i <= nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
            result = max(dp[i], result);
        }
        return result;
    }
};