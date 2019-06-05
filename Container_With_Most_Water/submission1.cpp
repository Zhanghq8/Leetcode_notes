#include <iostream>
#include <string>

using namespace std;

// Brute Force

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) {
            return 0;
        }
        int result = INT_MIN;
        for (int i=0; i<height.size()-1; i++) {
            for (int j=i+1; j<height.size(); j++) {
                int area = (j-i) * min(height[i], height[j]);
                if (area > result) {
                    result = area;
                }
            }
        }
        return result;
    }
};

