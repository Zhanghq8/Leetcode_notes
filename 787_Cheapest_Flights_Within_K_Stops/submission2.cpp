#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int,int>>> graph_;
        for (int i=0; i<flights.size(); i++) {
            graph_[flights[i][0]].emplace_back(flights[i][1], flights[i][2]);
        }
        int stop_count = K+1;
        int result = INT_MAX;
        int cost = 0;
        queue<pair<int, int>> Q;
        Q.push({src,cost});
        while (!Q.empty() && stop_count >= 0) {
            int size = Q.size();
            while (size > 0) {
                int top_node = Q.front().first;
                int new_cost = Q.front().second;
                Q.pop();
                if (top_node == dst) {
                    result = min(result, new_cost);
                }
                for (auto flight : graph_[top_node]) {
                    if (new_cost + flight.second > result) {
                        continue;
                    }
                    Q.push({flight.first, new_cost+flight.second});
                }
                size--;
            }
            stop_count--;
        }
        if (result == INT_MAX) {
            return -1;
        }
        return result;
    }
};