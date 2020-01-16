#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        nums_ = nums;
    }
    
    int pick(int target) {
        int cnt = 0;
        int result = -1;
        for (int i = 0; i < nums_.size(); i++) {
            if (nums_[i] != target) {
                continue;
            }
            cnt++;
            if (rand() % cnt == 0) {
                result = i;
            }
        }
        return result;
    }
private:
    vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
