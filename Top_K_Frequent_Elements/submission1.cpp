#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> map;
        priority_queue<pair<int, int>> pq;
        for (int i=0; i<nums.size(); i++) {
            map[nums[i]]++;
        }
        for (auto m:map) {
            pq.push({m.second, m.first});
        }
        for (int i=0; i<k; i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};