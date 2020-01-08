#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int left = 0;
        int result = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                result = max(result, i - left + 1);
            } else {
                left = i;
            }
        }
        return result;
    }
};