#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        multimap<int, pair<int, int>> mmap;
        int len1 = min(k, int(nums1.size()));
        int len2 = min(k, int(nums2.size()));
        for (int i=0; i<len1; i++) {
            for (int j=0; j<len2; j++) {
                mmap.insert({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
            }
        }
        for (auto it=mmap.begin(); it!=mmap.end(); it++) {
            result.push_back({it->second.first, it->second.second});
            k--;
            if (k<=0) {
                return result;
            }
        }
        return result;
    }
};