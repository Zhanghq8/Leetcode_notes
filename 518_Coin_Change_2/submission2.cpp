#include <iostream>
#include <string>

using namespace std;

// DFS

class Solution {
public:
    vector<vector<int>> change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end(), greater<int>());
        vector<vector<int>> result;
        vector<int> output;
        int target = amount;
        helper(result, output, coins, target, 0);
        return result;
    }
private:
    void helper (vector<vector<int>>& result, vector<int>& output, vector<int>& coins, int target, int index) {
        if (index == coins.size() - 1) {
            if (target % coins[index] == 0) {
                output.push_back(target / coins[index]);
                result.emplace_back(output);
            }
            return;
        }
        for (int i=0; i <= target/coins[index]; i++) {
            output.push_back(i);
            helper(result, output, coins, target - coins[index] * i, index+1);
            output.pop_back();
        }
    }
};
