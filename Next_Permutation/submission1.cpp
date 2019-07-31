#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty() == true) {
            return;
        }
        int i, j;
        for (i=nums.size()-2; i>=0; i--) {
            if (nums[i+1] > nums[i]) {
                for (j=nums.size()-1; j>i; j--) {
                    if (nums[j] > nums[i]) {
                        break;
                    }
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin()+i+1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
