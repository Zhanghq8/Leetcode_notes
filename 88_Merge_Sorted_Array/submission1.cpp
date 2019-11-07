#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int merge_index = m+n-1;
        int length1 = m-1;
        int length2 = n-1;
        while (length1 >=0 && length2 >= 0) {
            if (nums1[length1] >= nums2[length2]) {
                nums1[merge_index] = nums1[length1];
                merge_index--;
                length1--;
            }
            else {
                nums1[merge_index] = nums2[length2];
                merge_index--;
                length2--;
            }
        }
        while (length2 >= 0) {
            nums1[merge_index] = nums2[length2];
            merge_index--;
            length2--;
        }
    }
};

