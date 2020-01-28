#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> solution;
        sort(candidates.begin(), candidates.end());
        helper(result, solution, candidates, target, 0);
        return result;
    }
private:
    void helper(vector<vector<int>>& result, vector<int>& solution, vector<int>& candidates, int target, int                index) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            result.push_back(solution);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i-1]) {
                continue;
            }
            solution.push_back(candidates[i]);
            helper(result, solution, candidates, target - candidates[i], i + 1);
            solution.pop_back();
        }
    }
};