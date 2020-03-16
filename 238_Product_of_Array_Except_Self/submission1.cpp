#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> forward(nums.size() + 1, 1);
        vector<int> backward(nums.size() + 1, 1);
        for (int i = 1, j = nums.size() - 1; i <= nums.size() || j >= 0; i++, j--) {
            forward[i] = forward[i-1] * nums[i-1];
            backward[j] = backward[j+1] * nums[j];
        }
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            result[i] = forward[i] * backward[i+1];
        }
        return result;
    }
};