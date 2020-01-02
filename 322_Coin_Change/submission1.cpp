#include <iostream>
#include <string>

using namespace std;

// DFS

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend());
        int result = INT_MAX;
        helper(coins, 0, amount, 0, result);
        return result == INT_MAX ? -1 : result;
    }
private:
    void helper(vector<int>& coins, int index, int amount, int count, int& result) {
        if (amount == 0) {
            result = min(count, result);
        }
        if (index == coins.size()) {
            return;
        }
        for (int i=amount/coins[index]; i>=0 && count + i < result; i--) {
            helper(coins, index+1, amount-i*coins[index], count+i, result);
        }
    }
};

