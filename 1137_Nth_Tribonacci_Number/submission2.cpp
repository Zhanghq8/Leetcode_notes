#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
    	vector<int> memo(n + 1, -1);
    	return helper(n, memo);
    }
private:
	int helper(int n, vector<int>& memo) {
		if (memo[n] != -1) {
			return memo[n];
		}
        if (n == 0 || n == 1 || n == 2) {
            return n == 0 ? 0 : 1; 
        }
        memo[n] = helper(n - 1, memo) + helper(n - 2, memo) + helper(n - 3, memo);
        return memo[n];
	}
};