#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;

        auto compare = [](pair<int, string>& a, pair<int, string>& b) {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        };
        unordered_map<string, int> umap;
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(compare) > pq(compare);
        for (int i=0; i<words.size(); i++) {
            umap[words[i]]++;
        }
        for (auto n:umap) {
            pq.push({n.second, n.first});
        }
        for (int i=0; i<k; i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};