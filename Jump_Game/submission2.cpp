#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) {
            return true;
        }
        vector<int> dp(length-1);
        dp[0] = nums[0];
        int max_jump = dp[0]; 
        for (int i=1; i<length-1; i++) {
            if (max_jump >= i) {
                dp[i] = max(i+nums[i], dp[i-1]);
                max_jump = dp[i]; 
                if (dp[i] >= length-1) {
                return true;
                }
            }
            else {
                dp[i] = 0;
            }
        }
        return dp[length-2] >= length-1;
    }
};

