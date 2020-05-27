#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> umap;
        int length = 0;
        umap.insert({0, -1});
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if (umap.count(sum)) {
                length = max(length, i - umap[sum]);    
            } else {
                umap[sum] = i;
            }
        }
        return length;
    }
};