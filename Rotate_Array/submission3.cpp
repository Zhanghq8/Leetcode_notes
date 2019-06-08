#include <iostream>
#include <string>

using namespace std;

// Reverse

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0 || k % nums.size() == 0) {
            return;
        }
        reverse(nums.begin(), nums.begin() + nums.size() - k%nums.size());
        reverse(nums.begin() + nums.size() - k%nums.size(), nums.end());
        reverse(nums.begin(), nums.end());
    }
};

