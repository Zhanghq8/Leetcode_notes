#include <iostream>
#include <string>

using namespace std;

// Vector

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        for (int i = k; i > 0; i--) {
            nums.erase(nums.begin() + length - 1);
            nums.insert(nums.begin(), nums[length-1]);
        }
    }
};

