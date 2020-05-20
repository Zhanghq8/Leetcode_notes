#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> candidates(N + 1);
        for (int i = 0; i < trust.size(); i++) {
            candidates[trust[i][0]]--;
            candidates[trust[i][1]]++;
        }
        for (int i = 1; i < candidates.size(); i++) {
            if (candidates[i] == N - 1) {
                return i;
            }
        }
        return -1;
    }
};