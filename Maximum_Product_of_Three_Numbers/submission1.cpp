#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int max_1 = nums[n-1];
        int max_2 = nums[n-2];
        int max_3 = nums[n-3];
        int min_1 = nums[0];
        int min_2 = nums[1];
        return max(max_1*max_2*max_3, min_1*min_2*max_1);
    }
};