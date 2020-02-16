#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        int result = 0;
        unordered_map<int, int> umap;
        umap[0] = 1;
        int curSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            result += umap[curSum - k];
            umap[curSum]++;
        }
        return result;
    }
};