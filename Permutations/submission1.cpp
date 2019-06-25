#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helper(result, nums, 0);
        return result;
    }
private:
    void helper(vector<vector<int>>& result, vector<int>& nums, int start) {
        if (start >= nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i=start; i<nums.size(); i++) {
            swap(nums[start], nums[i]);
            helper(result, nums, start+1);
            swap(nums[start], nums[i]);
        }
    }
};

