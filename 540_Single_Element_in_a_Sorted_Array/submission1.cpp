#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int target = mid % 2 == 0 ? mid + 1 : mid - 1;
            if (nums[mid] == nums[target]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};