#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()) {
            return {};
        }
        vector<int> result (T.size(), 0);
        stack<int> S;
        for (int i = 0; i < T.size(); i++) {
            while (!S.empty() && T[i] > T[S.top()]) {
                result[S.top()] = i - S.top();
                S.pop();
            }
            S.push(i);
        }
        return result;
    }
};