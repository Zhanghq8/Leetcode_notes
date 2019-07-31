#include <iostream>
#include <math.h>

// Two pointers

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty() == true || s == 0) {
            return 0;
        }
        int min_length = INT_MAX;
        int left = 0, right = 0;
        vector<int> sums(nums.size());
        sums[0] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            sums[i] = sums[i-1] + nums[i];
        }
        while (left < nums.size() && right < nums.size()) {
            int sum;
            if (left == right) {
                sum = nums[left];
            }
            else {
                if (left < 1) {
                    sum = sums[right];
                }
                else {
                    sum = sums[right] - sums[left-1];
                }
            }
            if (sum >= s) {
                if (min_length > right - left + 1) {
                    min_length = right - left + 1;
                }
                left++;
            }
            else {
                right++;
            }
        }
        if (min_length == INT_MAX) {
            return 0;
        }
        return min_length;
    }
};
