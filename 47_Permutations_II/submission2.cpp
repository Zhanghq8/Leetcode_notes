#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> ans;
        helper(ans, nums, 0);
        result = vector<vector<int>> (ans.begin(), ans.end());
        return result;
    }
private:
    void helper(set<vector<int>>& ans, vector<int>& nums, int index) {
        if (index >= nums.size()) {
            ans.insert(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[index]) {
                continue;
            }
            swap(nums[i], nums[index]);
            helper(ans, nums, index + 1);
            swap(nums[i], nums[index]);
        }
    }
};