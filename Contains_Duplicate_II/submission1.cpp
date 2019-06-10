#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> u_map;
        for (int i=0; i<nums.size(); i++) {
            if (u_map.find(nums[i]) != u_map.end() && i - u_map[nums[i]] <= k) {
                return true;
            }
            else {
                u_map[nums[i]] = i;
            }
        }
        return false;
    }
};

