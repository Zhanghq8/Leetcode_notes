#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> output;
        sort(candidates.begin(), candidates.end());
        addsolution(result, output, candidates, 0, target);
        return result;
    }
private:
    void addsolution(vector<vector<int>>& result, vector<int>& output, vector<int>& candidates, int index, int target) {
        
        if (target < 0 ) {
            return;
        }
        if (target == 0) {
            result.push_back(output);
            return;
        }
        for (int i=index; i<candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;   
            }
            output.push_back(candidates[i]);
            addsolution(result, output, candidates, i+1, target-candidates[i]);
            output.pop_back();
        }
    }
};