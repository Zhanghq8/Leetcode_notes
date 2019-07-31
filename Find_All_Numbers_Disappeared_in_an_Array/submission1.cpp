#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result{};
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
                i--;
            }
        }
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != i+1) {
                result.push_back(i+1);
            }
        }
        return result;
    }
};