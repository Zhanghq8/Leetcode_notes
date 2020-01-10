#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        stack<int> S;
        vector<int> result(nums.size(), -1);
        for (int i = 0; i < 2 * nums.size(); i++) {
            int num = nums[i % nums.size()];
            while (!S.empty() && num > nums[S.top()]) {
                result[S.top()] = num;
                S.pop();
            }
            if (i < nums.size()) {
                S.push(i);
            }
        }
        return result;
    }
};