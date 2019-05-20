#include <iostream>
#include <string>

using namespace std;

// Two pointers

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int index = 0;
        int count = 1;
        for (int i=1; i<nums.size(); i++) {
            if (nums[index] != nums[i]) {
                index++;
                nums[index] = nums[i];
                count = 1;
            }
            else if (nums[index] == nums[i] && count < 2) {
                count++;
                index++;
                nums[index] = nums[i];
            }
        }
        return index+1;
    }
};

