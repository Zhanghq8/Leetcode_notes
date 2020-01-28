#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> solution;
        helper(result, solution, k, n, 1);
        return result;
    }
private:
    void helper(vector<vector<int>>& result, vector<int>& solution, int num, int target, int index) {
        if (solution.size() == num && target == 0) {
            result.push_back(solution);
            return;
        }
        if (target < 0 || solution.size() > num) {
            return;
        }
        for (int i = index; i <= 9; i++) {
            solution.push_back(i);
            helper(result, solution, num, target - i, i + 1);
            solution.pop_back();
        }
    }
};

