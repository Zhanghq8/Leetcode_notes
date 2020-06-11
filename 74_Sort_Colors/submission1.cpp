#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int index = 0;
        while(index <= right) {
            if (nums[index] == 2) {
                swap(nums[index], nums[right]);
                right--;
            } else if (nums[index] == 0) {
                swap(nums[index], nums[left]);
                left++;
                index++;
            } else {
                index++;
            }
        }
        return;
    }
};