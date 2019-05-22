#include <iostream>
#include <string>

using namespace std;

// Binary search

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int left = 0;
        int right = nums.size()-1;
        while (left < right) {
            int mid = (left + right)/2;
            if (nums[mid] > nums[right]) {
                left = mid+1;
            }
            else {
                right = mid;
            }
        }
        return nums[left];
    }
};
