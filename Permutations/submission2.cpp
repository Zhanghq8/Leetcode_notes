#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> element;
        vector<int> visited(nums.size(), 0);
        helper(result, visited, element, nums, 0);
        return result;
    }
private:
    void helper(vector<vector<int>>& result, vector<int>& visited, vector<int>& element, vector<int>& nums, int index) {
        if (element.size() >= visited.size()) {
            result.push_back(element);
            return;
        }
        for (int i=0; i<visited.size(); i++) {
            if (visited[i] == 1) {
                continue;
            }
            visited[i] = 1;
            element.push_back(nums[i]);
            helper(result, visited, element, nums, index+1);
            element.pop_back();
            visited[i] = 0;
        }
    }
};

