#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left=0, right=nums.size();
        while (left < right) {
            int mid = (right+left)/2;
            int cnt = 0;
            for (int i=0; i<nums.size(); i++) {
                if (nums[i] <= mid) {
                    cnt++;
                }
            }
            if (cnt <= mid) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};