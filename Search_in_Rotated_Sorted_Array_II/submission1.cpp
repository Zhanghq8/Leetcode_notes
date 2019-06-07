#include <iostream>
#include <string>

using namespace std;

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return true;
            }
            else if (nums[mid] > nums[right]) {
                if (nums[left] <= target && nums[mid] > target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else if (nums[mid] < nums[right]) {
                if (nums[right] >= target && nums[mid] < target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }               
            }
            else {
                right--;
            }
        }
        return false;
    }
};




