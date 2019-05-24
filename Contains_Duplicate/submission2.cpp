#include <iostream>
#include <string>

using namespace std;

// Hash Table

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> u_map;
        for (auto n:nums) {
            if (u_map.find(n) != u_map.end()) { //if not find n, return end().
                return true;
            }
            ++u_map[n]; // the first call to operator[] initialized the counter with zero
        }
        return false;
    }
};

