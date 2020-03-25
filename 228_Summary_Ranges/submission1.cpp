#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int left = 0; 
        while (left < nums.size()) {
            int right = 1;
            while (left + right < nums.size() && (long)nums[left + right] - nums[left] == right) {
                right++;
            }
            result.emplace_back(right <= 1 ? to_string(nums[left]) : to_string(nums[left]) + "->" + to_string(nums[left + right - 1]));
            left += right;
        }
        return result;
    }
};