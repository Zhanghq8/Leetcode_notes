#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int k = (nums1.size() + nums2.size() + 1)/2;
        int left = 0, right = nums1.size(), first = 0, second = 0;
        while (left < right) {
            first = left + (right-left)/2;
            second = k - first;
            if (nums1[first] < nums2[second-1]) {
                left = first+1;
            }
            else {
                right = first;
            }
        }
        first = left;
        second = k - left;
        int left_median = max(first <= 0 ? INT_MIN : nums1[first - 1], 
                           second <= 0 ? INT_MIN : nums2[second - 1]);
        if ((nums1.size() + nums2.size())%2 == 1) {
            return left_median;
        }
        int right_median = min(first >= nums1.size() ? INT_MAX : nums1[first], 
                           second >= nums2.size() ? INT_MAX : nums2[second]);
        return (left_median + right_median)*0.5;
    }
};
