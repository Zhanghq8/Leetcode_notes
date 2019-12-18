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
        result.emplace_back(output);
        for (int i=index; i<nums.size(); i++) {
            if (i > index && nums[i] == nums[i-1]) {
                continue;
            }
            output.push_back(nums[i]);
            helper(result, nums, output, i+1);
            output.pop_back();
        }
    }
};

