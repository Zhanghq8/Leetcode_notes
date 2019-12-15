#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> output;
        helper(result, output, nums, 0);
        return result;
    }
private:
    void helper(vector<vector<int>>& result, vector<int>& output, vector<int>& nums, int level) {
        if (level == nums.size()) {
            result.emplace_back(output);
            return;
        }
        helper(result, output, nums, level+1);
        output.push_back(nums[level]);
        helper(result, output, nums, level+1);
        output.pop_back();
    }
};

