#include <iostream>
#include <string>

using namespace std;

//count the number, and overwrite the vector.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num_red = 0;
        int num_white = 0;
        int num_blue = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                num_red++;
            }
            else if (nums[i] == 1) {
                num_white++;
            }
            else {
                num_blue++;
            }
        }
        for (int i=0; i<nums.size(); i++) {
            if (i<num_red) {
                nums[i] = 0;
            }
            else if (i>=num_red && i<num_red+num_white) {
                nums[i] = 1;
            }
            else {
                nums[i] = 2;
            }
        }
    }
};

