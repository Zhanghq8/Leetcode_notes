#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result{-1, -1};
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        if (right == nums.size() || nums[right] != target) {
            return result;
        }
        result[0] = right;
        right = nums.size();
        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] <= target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        result[1] = right - 1;
        return result;
    }
};
