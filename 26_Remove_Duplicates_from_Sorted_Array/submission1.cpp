#include <iostream>
#include <string>
#include <vector>

using namespace std;

// slow pointer 0
// fast pointer 1
// Traverse the vector by fast pointer, check if the element at slow ptr is equal to the
// fast pointer. If so, fast ptr++, otherwise, copy the value at fast ptr to slow ptr + 1
// and fast ptr++


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int index = 0;
        for (int i=1; i<nums.size(); i++) {
            if (nums[index] != nums[i]) {
                index++;
                nums[index] = nums[i];
            }
        }
        return index+1;
    }
};

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         if (nums.size() <= 1) {
//             return nums.size();
//         }
//         int slow = 0;
//         int fast = 1;
//         while (slow < nums.size() && fast < nums.size()) {
//             if (nums[slow] == nums[fast]) {
//                 fast++;
//             }
//             else {
//                 slow++;
//                 nums[slow] = nums[fast];
//                 fast++;
//             }
//         }
//         return slow+1;
//     }
// };
