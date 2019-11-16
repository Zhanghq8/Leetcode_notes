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
        vector<bool> visited(n, false);
        int stop_count = K;
        int result = INT_MAX;
        int cost = 0;
        dfs(graph_, visited, stop_count, result, src, dst, cost);
        if (result == INT_MAX) {
            return -1;
        }
        return result;
    }
private:
    void dfs(unordered_map<int, vector<pair<int,int>>>& graph_, vector<bool>& visited, 
             int stop_count, int &result, int src, int dst, int cost) {
        if (src == dst) {
            result = cost;
            return;
        }
        if (stop_count < 0) {
            return;
        }
        for (auto flight : graph_[src]) {
            if (visited[flight.first]) {
                continue;
            }
            if (cost + flight.second > result) {
                continue;    
            }
            visited[flight.first] = true;
            dfs(graph_, visited, stop_count-1, result, flight.first, dst, cost+flight.second);
            visited[flight.first] = false;
        }
    }
};