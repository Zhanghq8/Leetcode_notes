#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size();
        int left, right;
        while (head < tail) {
            int mid = (head + tail)/2;
            if (nums[mid] >= target) {
                tail = mid;
            }
            else {
                head = mid + 1;
            }
        }
        left = head;
        tail = nums.size();
        while (head < tail) {
            int mid = (head + tail)/2;
            if (nums[mid] > target) {
                tail = mid;
            }
            else {
                head = mid + 1;
            }
        }
        right = tail;
        if (left == right) {
            return vector<int> (2,-1);
        }
        else {
            return vector<int> {left, right-1};
        }
    }
};

