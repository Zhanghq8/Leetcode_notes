#include <iostream>
#include <math.h>

// Brute force(TLE)

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int min_length = INT_MAX;
        if (nums.empty() == true || s == 0) {
            return 0;
        }
        for (int i=0; i<nums.size(); i++) {
            for (int j=i; j<nums.size(); j++) {
                int sum = 0;
                int index = i;
                while (index <= j) {
                    sum += nums[index];
                    index++;
                }
                if (sum >= s) {
                    if (min_length > j-i+1) {
                        min_length = j-i+1;
                    }
                }
            }
        }
        if (min_length == INT_MAX) {
            return 0;
        }
        return min_length;
    }
};
