#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.empty() ? 0 : nums[0];
        }
        return max(helper(nums, 0, nums.size() - 1), helper(nums, 1, nums.size()));
    }
    int helper(vector<int>& nums, int left, int right) {
        if (right - left <= 1) {
            return nums[left];
        }
        vector<int> dp (right, 0);
        dp[left] = nums[left];
        dp[left + 1] = max(nums[left], nums[left + 1]);
        for (int i = left + 2; i < dp.size(); i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        } 
        return dp.back();
    }
};