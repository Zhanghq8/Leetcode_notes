#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max_1 = INT_MIN;
        int max_2 = INT_MIN;
        int max_3 = INT_MIN;
        int min_1 = INT_MAX;
        int min_2 = INT_MAX;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > max_1) {
                max_3 = max_2;
                max_2 = max_1;
                max_1 = nums[i];
            }
            else if (nums[i] > max_2) {
                max_3 = max_2;
                max_2 = nums[i];
            }
            else if (nums[i] > max_3) {
                max_3 = nums[i];
            }
            if (nums[i] < min_1) {
                min_2 = min_1;
                min_1 = nums[i];
            }
            else if (nums[i] < min_2) {
                min_2 = nums[i];
            }            
        }
        return max(max_1*max_2*max_3, min_1*min_2*max_1);
    }
};