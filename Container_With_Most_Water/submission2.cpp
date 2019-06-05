#include <iostream>
#include <string>

using namespace std;

// Two Pointers

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) {
            return 0;
        }
        int result = INT_MIN;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int area = (right-left) * min(height[left], height[right]);
            if (area > result) {
                result = area;
            }
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return result;
    }
};

