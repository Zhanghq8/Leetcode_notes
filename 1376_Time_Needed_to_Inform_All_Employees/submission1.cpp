#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> employees(n);
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i] == -1) {
                continue;
            }
            employees[manager[i]].push_back(i);
        }
        return helper(headID, informTime, employees);
    }
    int helper(int headID, vector<int>& informTime, vector<vector<int>>& employees) {
        int time = 0;
        for (int i = 0; i < employees[headID].size(); i++) {
            time = max(time, helper(employees[headID][i], informTime, employees));
        }
        return informTime[headID] + time;
    }
};