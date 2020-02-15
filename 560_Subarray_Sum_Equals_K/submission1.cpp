#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        int result = 0;
        vector<int> prefixSum(nums.size()+1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (prefixSum[j+1] - prefixSum[i] == k) {
                    result++;
                }
            }
        }
        return result;
    }
};