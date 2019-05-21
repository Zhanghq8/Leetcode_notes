#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int result = nums[0];
        vector<int> dp_max(nums.size());
        vector<int> dp_min(nums.size());
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            dp_max[i] = max(nums[i], max(dp_max[i-1]*nums[i], dp_min[i-1]*nums[i]));
            dp_min[i] = min(nums[i], min(dp_min[i-1]*nums[i], dp_max[i-1]*nums[i]));
            if (result < dp_max[i]) {
                result = dp_max[i];
            }
        }
        return result;
    }
};

