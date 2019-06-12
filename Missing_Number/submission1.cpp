#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int length = nums.size();
        for (int i=0; i<length; i++) {
            sum += nums[i];
        }
        int temp = length * (length + 1) / 2;
        return temp - sum;
    }
};
