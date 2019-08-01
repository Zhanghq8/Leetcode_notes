#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i=0; i<k; i++) {
            sum += nums[i];
        }
        double max_sum = sum;
        for (int i=k; i<nums.size(); i++) {
            sum  = sum - nums[i-k] + nums[i];
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
        return max_sum / k;
    }
};