#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }
        int maxArea = 0;
        stack<int> greater;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            int area = 0;
            while (!greater.empty() && heights[i] <= heights[greater.top()]) {
                int top = greater.top();
                greater.pop();
                if (greater.empty()) {
                    area = heights[top] * i;
                } else {
                    area = heights[top] * (i - greater.top() - 1);
                }
                maxArea = max(area, maxArea);
            }
            greater.push(i);
        }
        return maxArea;
    }
};