#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int result = INT_MIN;
        int pre = 0;
        int next = 0;
        unordered_set uset(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++) {
            if (uset.count(nums[i]) == 0) {
                continue;
            }
            pre = nums[i] - 1;
            next = nums[i] + 1;
            uset.erase(nums[i]);
            while (uset.count(pre) != 0) {
                uset.erase(pre);
                pre--;
            }
            while (uset.count(next) != 0) {
                uset.erase(next);
                next++;
            }
            result = max(result, next-pre-1);
            cout << result << endl;
        }
        return result;
    }
};
