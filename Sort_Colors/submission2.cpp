#include <iostream>
#include <string>

using namespace std;

//Two pointers.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int length = nums.size();
        int red_index = 0;
        int blue_index = length - 1;
        for (int i=0; i<blue_index+1; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[red_index]);
                red_index++;
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[blue_index]);
                blue_index--;
                i--;
            }
        }
    }
};

