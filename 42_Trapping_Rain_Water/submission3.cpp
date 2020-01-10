#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> monoStack;
        int result = 0;
        int left = 0;
        while (left < height.size()) {
            if (monoStack.empty() || height[monoStack.top()] >= height[left]) {
                monoStack.push(left);
                left++;
            } else {
                int minIndex = monoStack.top();
                monoStack.pop();
                if (monoStack.empty()) {
                    continue;
                }
                result += (min(height[left], height[monoStack.top()]) - height[minIndex]) * (left - monoStack.top() - 1);
            }
        }
        return result;
    }
};