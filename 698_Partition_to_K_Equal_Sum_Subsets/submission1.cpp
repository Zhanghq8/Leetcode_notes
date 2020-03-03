#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % k) {
            return false;
        }
        vector<bool> visited(nums.size(), false);
        bool result = helper(visited, nums, k, sum/k, 0, 0);
        return result;
    }
private:
    bool helper(vector<bool>& visited, vector<int>& nums, int k, int target, int index, int curSum) {
        if (k == 1) {
            return true;
        }
        if (curSum == target) {
            return helper(visited, nums, k - 1, target, 0, 0);
        }
        if (curSum > target) {
            return false;
        }
        for (int i = index; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            if (helper(visited, nums, k, target, i + 1, curSum + nums[i])) {
                return true;
            }
            visited[i] = false;
        }
        return false;
    }
};