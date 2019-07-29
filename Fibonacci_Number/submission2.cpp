#include <iostream>
#include <string>

using namespace std;

// Memo Recursive(Top-down)

class Solution {
public:
    int fib(int N) {
        vector<int> memo(N+1, -1);
        return helper(N, memo);
    }
private:
    int helper(int N, vector<int>& memo) {
        if (memo[N] != -1) {
            return memo[N];
        }
        if (N <= 1) {
            memo[N] = N;
            return memo[N];
        }
        memo[N] = helper(N-1, memo) + helper(N-2, memo);
        return memo[N];        
    }
};

