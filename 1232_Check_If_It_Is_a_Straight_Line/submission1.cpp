#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() <= 2) {
            return true;
        }
        int x1 = coordinates[0][0];
        int xDiff = coordinates[1][0] - x1;
        int y1 = coordinates[0][1];
        int yDiff = coordinates[1][1] - y1;
        for (int i = 2; i < coordinates.size(); i++) {
            int temp1 = (coordinates[i][0] - x1) * yDiff;
            int temp2 = (coordinates[i][1] - y1) * xDiff;
            if (temp1 != temp2) {
                return false;
            }
        }
        return true;
    }
};