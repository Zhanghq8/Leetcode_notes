#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result;
        unordered_map<int, int> umap;
        for (int i=0; i<nums.size(); i++) {
            umap[nums[i]]++;
        }
        for (auto u : umap) {
            if (u.second == 1) {
                result = u.first;
            }
        }
        return result;
    }
};