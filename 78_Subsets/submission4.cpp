#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> output;
        for (int i=0; i<=nums.size(); i++) {
            helper(result, output, nums, i, 0);
        }
        return result;
    }
private:
    void helper(vector<vector<int>>& result, vector<int>& output, vector<int>& nums, int size, int index) {
        if (output.size() == size) {
            result.emplace_back(output);
            return;
        }
        for (int i=index; i<nums.size(); i++) {
            output.push_back(nums[i]);
            helper(result, output, nums, size, i+1);
            output.pop_back();
        }
    }
};

