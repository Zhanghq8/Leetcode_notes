#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        if (light.empty()) {
            return 0;
        }
        int max = 0;
        int result = 0;
        for (int i = 0; i < light.size(); i++) {
            if (light[i] >= max) {
                max = light[i];
            }
            if (max <= i+1) {
                result++;
            }
        }
        return result;
    }
};
