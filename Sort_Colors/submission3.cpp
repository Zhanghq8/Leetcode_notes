#include <iostream>
#include <string>

using namespace std;

//Iterative.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int length = nums.size();
        int red_index = 0;
        int blue_index = length - 1;
        int index = 0;
        while (index <= blue_index) {
            if (nums[index] == 0) {
                swap(nums[index], nums[red_index]);
                red_index++;
                index++;
            }
            else if (nums[index] == 2) {
                swap(nums[index], nums[blue_index]);
                blue_index--;
            }
            else {
                index++;
            }
        }
    }
};

