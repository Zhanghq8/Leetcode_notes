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
    void helper(vector<vector<int>>& result, vector<int>& output, vector<int>& nums, int index) {
        result.emplace_back(output);
        for (int i=index; i<nums.size(); i++) {
            output.push_back(nums[i]);
            helper(result, output, nums, i+1);
            output.pop_back();
        }
    }
};
