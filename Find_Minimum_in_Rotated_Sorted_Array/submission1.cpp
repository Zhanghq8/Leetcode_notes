#include <iostream>
#include <string>

using namespace std;

// Two pointers

class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) {
            return nums[0];
        }
        for (int i=0; i<length-1; i++) {
            if ((nums[i]) > nums[i+1]) {
                return nums[i+1];
            }
        }
        return nums[0];
    }
};

