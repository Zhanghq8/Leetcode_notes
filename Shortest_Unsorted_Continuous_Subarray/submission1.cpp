#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums_copy = nums;
        sort(nums_copy.begin(), nums_copy.end());
        int left = nums.size();
        int right = -1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != nums_copy[i]) {
                left = min(left, i);
                right = max(right, i);
            }
        }
        if (left == nums.size() && right == -1) {
            return 0;
        }
        return right - left + 1;
    }
};