#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        string result = "";
        unordered_map<char, int> umap;
        priority_queue<pair<int, char>> pq;
        for (int i=0; i<S.size(); i++) {
            umap[S[i]]++;
        }
        for (auto u : umap) {
            pq.push({u.second, u.first});
            if (pq.top().first > (S.size()+1) / 2) {
                return result;
            }
        }
        
        while (pq.size() >= 2) {
            auto t1 = pq.top(); 
            pq.pop();
            auto t2 = pq.top(); 
            pq.pop();
            t1.first--;
            t2.first--;
            result.push_back(t1.second);
            result.push_back(t2.second);
            if (t1.first > 0) {
                pq.push(t1);
            }
            if (t2.first > 0) {
                pq.push(t2);
            }
        }
        if (pq.empty() == true) {
            return result;
        }
        result.push_back(pq.top().second);
        return result;
        
    }
};