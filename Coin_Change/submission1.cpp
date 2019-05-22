#include <iostream>
#include <string>

using namespace std;

// Recusion

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int result = INT_MAX;
        int n = coins.size();
        sort(coins.begin(), coins.end());
        helper(coins, n - 1, amount, 0, result);
        if (result == INT_MAX) {
            return -1;
        }
        else {
            return result;
        }
    }
    void helper(vector<int>& coins, int start, int target, int cur, int& res) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            res = min(res, cur);
            return;
        }
        for (int i = start; i >= 0; i--) {
            if (target%coins[i] == 0) {
                cur = cur+target/coins[i];
                helper(coins, i, 0, cur, res);
            }
            else {
                helper(coins, i, target - coins[i], cur + 1, res);
            }
        }
    }
};
