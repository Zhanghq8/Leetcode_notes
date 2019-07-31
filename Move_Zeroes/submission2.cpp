#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Two pointers

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != 0) {
                continue;
            }
            else {
                for (int j=i+1; j<nums.size(); j++) {
                    if (nums[j] == 0) {
                        continue;
                    }
                    else {
                        nums[i] = nums[j];
                        nums[j] = 0;
                        break;
                    }
                }
            }
        }
    }
};