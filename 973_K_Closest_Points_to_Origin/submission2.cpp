#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result; 
        priority_queue<pair<int, vector<int>>> pq;
        for (int i=0; i<points.size(); i++) {
            pq.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], points[i]);
            if (pq.size() > K) {
                pq.pop();
            }
        }
        while (!pq.empty()) {
            result.emplace_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};