#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.empty()) {
            return false;
        }
        vector<int> colors(graph.size(), 0);
        for (int i=0; i<graph.size(); i++) {
            if (!colors[i] && !coloring(graph, colors, 1, i)) {
                return false;
            }
        }
        return true;
    }
private:
    bool coloring(vector<vector<int>>& graph, vector<int>& colors, int color, int id) {
        if (colors[id]) {
           return colors[id] == color;
        }
        colors[id] = color;
        for (int i=0; i<graph[id].size(); i++) {
            if (!coloring(graph, colors, -color, graph[id][i])) {
                return false;
            }
        }
        return true;
    }
};