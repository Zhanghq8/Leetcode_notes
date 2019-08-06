#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        string result;
        unordered_map<char, int> umap;
        priority_queue<pair<int, char>> pq;
        for (int i=0; i<s.size(); i++) {
            umap[s[i]]++;
        }   
        for (auto n:umap) {
            pq.push({n.second, n.first});
        }
        while (pq.empty() != true) {
            int cnt = pq.top().first;
            while (cnt > 0) {
                result.push_back(pq.top().second);
                cnt--;
            }
            pq.pop();
        }
        return result;
    }
};