#include <iostream>
#include <string>

using namespace std;

// Hash Table

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> u_map;
        for (auto n:nums) {
            ++u_map[n];
            if (u_map[n] > nums.size()/2) {
                return n;
            }
        }
        return 0;
    }
};