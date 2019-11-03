#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }
        vector<vector<int>> result;
        int index = 0;
        while (index < intervals.size() && intervals[index][1] < newInterval[0]) {
            result.push_back(intervals[index]);
            index++;
        }
        while (index < intervals.size() && intervals[index][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[index][0], newInterval[0]);
            newInterval[1] = max(intervals[index][1], newInterval[1]);
            index++;
        }
        result.push_back({newInterval[0], newInterval[1]});
        while (index < intervals.size()) {
            result.push_back({intervals[index][0], intervals[index][1]});
            index++;
        }
        return result;
    }
};