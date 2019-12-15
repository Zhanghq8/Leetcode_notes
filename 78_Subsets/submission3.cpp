#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = helper(nums, 0);
        return result;
    }
private:
    vector<vector<int>> helper(vector<int>& nums, int level) {
        if (level == nums.size()) {
            vector<vector<int>> result;
            result.push_back({});
            return result;
        }
        vector<vector<int>> lastRes = helper(nums, level+1);
        vector<vector<int>> newRes = lastRes;
        for (auto res : lastRes) {
            res.push_back(nums[level]);
            newRes.push_back(res);
        }
        return newRes;
    }
};

