#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        helper(result, S, 0);
        return result;
    }
private:
    void helper(vector<string>& result, string& S, int index) {
        if (index >= S.size()) {
            result.emplace_back(S);
            return;
        }
        helper(result, S, index + 1);
        if (S[index] - '0' >= 0 && S[index] - '0' <= 9) {
            return;
        }
        if (S[index] - 'A' >= 0 && S[index] - 'A' <= 26) {
            S[index] = S[index] + 32;
            helper(result, S, index + 1);
            S[index] = S[index] - 32;
        } else {
            S[index] = S[index] - 32;
            helper(result, S, index + 1);
            S[index] = S[index] + 32;
        }
    }
};