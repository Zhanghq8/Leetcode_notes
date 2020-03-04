#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) {
            nums;
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> output;
        helper(result, nums, output, 0);
        return result;
    }
private: 
    void helper(vector<vector<int>>& result, vector<int>& nums, vector<int>& output, int index) {
        if (index == nums.size()) {
            result.emplace_back(output);
            return;
        }
        output.push_back(nums[index]);
        helper(result, nums, output, index+1);
        output.pop_back();
        while (index < nums.size() - 1 && nums[index+1] == nums[index]) {
            index++;
        }
        helper(result, nums, output, index+1);
    }
};

