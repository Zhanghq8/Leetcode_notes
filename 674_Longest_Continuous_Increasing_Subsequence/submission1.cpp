#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int curLength = 1;
        int maxLength = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                curLength++;
            } else {
                curLength = 1;
            }
            maxLength = max(curLength, maxLength);
        }
        return maxLength;
    }
};