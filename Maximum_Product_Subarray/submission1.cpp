#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size()-1;
        for (int i=length; i>=0; i--) {
            if (nums[i]+i >= length) {
                length = i;
            }
        }
        return length == 0;
    }
};

