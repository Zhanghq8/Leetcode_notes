#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> output;
        vector<bool> visited(nums.size(), false);
        helper(result, output, visited, nums);
        return result;
    }
private:
    void helper(vector<vector<int>>& result, vector<int>& output, vector<bool>& visited, vector<int>& nums) {
        if (output.size() == nums.size()) {
            result.emplace_back(output);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            output.push_back(nums[i]);
            helper(result, output, visited, nums);
            output.pop_back();
            visited[i] = false;
        }
    }
};