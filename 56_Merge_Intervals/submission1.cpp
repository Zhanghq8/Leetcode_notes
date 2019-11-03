#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i][0] == result.back()[0]) {
                if (intervals[i][1] == result.back()[1]) {
                    continue;
                }
                else {
                    result.pop_back();
                    result.push_back({intervals[i][0], intervals[i][1]});
                }
            }
            else {
                if (intervals[i][0] <= result.back()[1]) {
                    result.back()[1] = max(intervals[i][1], result.back()[1]);
                }
                else {
                    result.push_back({{intervals[i][0], intervals[i][1]}});
                }
            }

        }
        return result;
    }
};