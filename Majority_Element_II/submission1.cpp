#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        if (nums.size() == 0) {
            return result;
        }
        if (nums.size() == 1) {
            result.push_back(nums[0]);
            return result;
        }
        sort(nums.begin(), nums.end());
        int count = 1;
        int mEle = nums[0];
        int length = nums.size();
        if (count > length/3) {
            result.push_back(nums[0]);
        }
        for (int i=1; i<length; i++) {
            if (nums[i] == nums[i-1]) {
                count++;
            }
            else {
                count = 1;
            }
            if (count > length/3 && result.size() == 0) {
                result.push_back(nums[i]);
            }
            else if (count > length/3 && nums[i] != result.back()) {
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};
