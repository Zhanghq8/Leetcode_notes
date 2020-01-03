#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int curSum = 0;
        int start = 0;
        for (int i=0; i<gas.size(); i++) {
            total += gas[i] - cost[i];
            curSum += gas[i] - cost[i];
            if (curSum < 0) {
                curSum = 0;
                start = i+1;
            }
        }
        return total < 0 ? -1 : start;
    }
};