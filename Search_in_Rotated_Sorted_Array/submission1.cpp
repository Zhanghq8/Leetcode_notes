#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        //find pivot index
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
        //search in the left part
        int subleft1 = 0;
        int subright1 = left;
        while (subleft1 < subright1) {
            int submid1 = (subleft1+subright1)/2;
            if (nums[submid1] == target) {
                return submid1;
            }
            else if (nums[submid1] < target) {
                subleft1 = submid1+1;
            }
            else {
                subright1 = submid1;
            }
        }
        //search in the right part
        int subleft2 = left;
        int subright2 = nums.size();
        while (subleft2 < subright2) {
            int submid2 = (subleft2+subright2)/2;
            if (nums[submid2] == target) {
                return submid2;
            }
            else if (nums[submid2] < target) {
                subleft2 = submid2+1;
            }
            else {
                subright2 = submid2;
            }
        }
        return -1;
    }
};

