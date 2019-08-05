#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int left = 0;
        int cnt = 0;
        int product = 1;
        for (int i=0; i<nums.size(); i++) {
            product *= nums[i];
            while (product >= k) {
                product /= nums[left];
                left++;
            }          
            cnt += i - left + 1;
        }
        return cnt;
    }
};