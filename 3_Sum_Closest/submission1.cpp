#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int length = nums.size();
        if (length < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int result;
        int diff = INT_MAX;
        if (nums[0]+nums[1]+nums[2] >= target) {
            return nums[0]+nums[1]+nums[2];
        }
        for (int k=0; k<length-2; k++) {
            int i = k+1;
            int j = length-1;
            while (i<j) {
                int temp = nums[i]+nums[j]+nums[k];
                if (abs(target-temp) < diff) {
                    diff = abs(target-temp);
                    result = temp;
                }
                if (temp > target) {
                    j--;
                }
                else if (temp < target) {
                    i++;
                }
                else {
                    return temp;
                }
            }
        }
        return result;
    }
};
