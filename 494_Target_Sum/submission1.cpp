#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int result = 0;
        int sum = 0;
        dfs(nums, S, sum, result, 0);
        return result;
    }
private:
    void dfs(vector<int>& nums, int S, int sum, int& result, int index) {
        if (index >= nums.size()) {
            if (sum == S) {
                result++;
            }
            return;
        }
        dfs(nums, S, sum - nums[index], result, index+1);
        dfs(nums, S, sum + nums[index], result, index+1);
    }
};
