#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur_sub;
        dfs(nums, result, cur_sub, 0);
        return result;
    }
private:
    void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& cur_sub, int index) {
        unordered_set<int> u_set;
        for (int i=index; i<nums.size(); i++) {
            if (cur_sub.empty() != true && nums[i] < cur_sub.back()) {
                continue;
            }
            if (u_set.count(nums[i]) >= 1) {
                continue;
            }
            u_set.insert(nums[i]);
            cur_sub.push_back(nums[i]);
            if (cur_sub.size() > 1) {
                result.push_back(cur_sub);
            }
            dfs(nums, result, cur_sub, i+1);
            cur_sub.pop_back();
        }
    }
};
