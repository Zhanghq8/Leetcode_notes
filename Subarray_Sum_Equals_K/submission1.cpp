#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty() == true) {
            return 0;
        }
        int cnt = 0;
        vector<int> sums(nums.size());
        sums[0] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            sums[i] = sums[i-1] + nums[i];
        }
        for (int i=0; i<nums.size(); i++) {
            for (int j=i; j<nums.size(); j++) {
                int sum;
                if (i == j) {
                    sum = nums[i];
                }
                else {
                    if (i < 1) {
                        sum = sums[j];
                    }
                    else {
                        sum = sums[j] - sums[i-1];
                    }
                }
                if (sum == k) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};