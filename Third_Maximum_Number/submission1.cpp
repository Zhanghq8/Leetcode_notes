#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = nums[0];
        long second = LONG_MIN;
        long third = LONG_MIN;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] > first) {
                third = second;
                second = first;
                first = nums[i];
            }
            else if (nums[i] < first && nums[i] > second) {
                third = second;
                second = nums[i];
            }
            else if (nums[i] > third && nums[i] < second) {
                third = nums[i];
            }
        }
        if (third == LONG_MIN) {
            return first;
        }
        return third;
    }
};