#include <iostream>
#include <string>

using namespace std;

// Sort first, then binary search

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return false;
        }
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = (left+right)/2;
            if (nums[mid] == target) {
                return true;
            }
            else if (nums[mid] < target) {
                left = mid+1;
            }
            else {
                right = mid;
            }
        }
        return false;
    }
};

