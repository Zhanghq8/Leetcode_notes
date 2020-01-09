#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int index = partition(nums, left, right);
            if (index == k - 1) {
                break;
            }
            if (index < k - 1) {
                left = index + 1;
            } else {
                right = index - 1;
            }
        }
        return nums[k-1];
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int i = left + 1;
        int j = right;
        while (i <= j) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[j]);
                j--;
            } else {
                i++;
            }
        }
        swap(nums[j], nums[left]);
        return j;
    }
};
