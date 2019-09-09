#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// BFS
// track the index which start from at itself

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> solution;
        sort(candidates.begin(), candidates.end());
        helper(result, solution, 0, target, candidates);
        return result;
    }
private:
    void helper(vector<vector<int>>& result, vector<int>& solution, int index, int target, vector<int>& candidates) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            result.push_back(solution);
        }
        else {
            for (int i=index; i<candidates.size(); i++) {
                solution.push_back(candidates[i]);
                helper(result, solution, i, target-candidates[i], candidates);
                solution.pop_back();
            }
        }
    }
};
