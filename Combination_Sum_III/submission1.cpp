#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> output;
        addsolution(result, output, 1, n, k);
        return result;
    }
private:
    void addsolution(vector<vector<int>>& result, vector<int>& output, int index, int target, int size) {
        if (target < 0 || output.size() > size) {
            return;
        }
        if (target == 0 && output.size() == size) {
            result.push_back(output);
            return;
        }
        for (int i=index; i<10; i++) {
            if (i > index && i == i - 1) {
                continue;   
            }
            output.push_back(i);
            addsolution(result, output, i+1, target-i, size);
            output.pop_back();
        }
    }
};

