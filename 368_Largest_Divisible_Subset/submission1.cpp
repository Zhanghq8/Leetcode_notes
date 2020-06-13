#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<int> result;
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        vector<int> prevIndex(nums.size(), -1);
        int maxIndex = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[i] < dp[j] + 1 && nums[i] % nums[j] == 0) {
                    dp[i] = dp[j] + 1;
                    prevIndex[i] = j; 
                }
            }
            if (dp[maxIndex] < dp[i]) {
                maxIndex = i;
            }
        }
        while (maxIndex >= 0)  {
            result.push_back(nums[maxIndex]);
            maxIndex = prevIndex[maxIndex];
        }
        return result;
    }
};