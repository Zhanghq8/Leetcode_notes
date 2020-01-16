#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int slow = 1;
        int fast = 1;
        int size = nums.size();
        while (slow < size && fast < size) {
            if (nums[slow-1] == nums[fast]) {
                fast++;
            } else {
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
        }
        return slow;
    }
};