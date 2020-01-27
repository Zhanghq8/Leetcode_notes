#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> solution;
        helper(result, solution, n, k, 1);
        return result;
    }
private:
    void helper(vector<vector<int>>& result, vector<int>& solution, int num, int k, int index) {
        if (solution.size() == k) {
            result.push_back(solution);
            return;
        }
        if (index > num) {
            return;
        }
        helper(result, solution, num, k, index + 1);
        solution.push_back(index);
        helper(result, solution, num, k, index + 1);
        solution.pop_back();
    }
};

// Recursion tree
//                    []
//                 /       \
//                1         []
//              /   \     /   \
//             12    1     2    []
//            /  \  / \   / \   / \
//          123 12 13 1  23  2  3  []