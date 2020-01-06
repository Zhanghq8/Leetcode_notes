#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> dp(height.size(), 0);
        int result = 0;
        int curMax = 0;
        for (int i = 0; i < height.size(); i++) {
            dp[i] = curMax;
            curMax = max(curMax, height[i]);
        }
        curMax = 0;
        for (int i = height.size()-1; i >= 0; i--) {
            int minHeight = min(curMax, dp[i]);
            if (minHeight > height[i]) {
                result += minHeight - height[i];
            }
            curMax = max(curMax, height[i]);
        }
        return result;
    }
};