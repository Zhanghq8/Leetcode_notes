#include <iostream>
#include <string>

using namespace std;

// Boyer-Moore Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = nums[0];
        int count = 1;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] == result) {
                count++;
            }
            else if (nums[i] != result && count == 0) {
                result = nums[i];
                count++;
            }
            else if (nums[i] != result && count >=1) {
                count--;
            }
        }
        return result;
    }
};

