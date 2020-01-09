#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        nums_ = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result = nums_;
        for (int i = 0; i < result.size(); i++) {
            int randomIndex = rand() % (result.size() - i) + i;
            swap(result[i], result[randomIndex]);
        }
        return result;
    }
    vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */