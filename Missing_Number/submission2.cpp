#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i=0; i<length; i++) {
            if (i != nums[i]) {
                return i;
            }
        }
        return nums[length-1] + 1;
    }
};
