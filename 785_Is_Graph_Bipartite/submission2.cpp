#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), 0);
        for (int i=0; i<graph.size(); i++) {
            if (!colors[i]) {
                queue<int> Q;
                Q.push(i);
                colors[i] = 1;
                while (!Q.empty()) {
                    int curr = Q.front();
                    Q.pop();
                    int color = colors[curr];
                    for (auto id : graph[curr]) {
                        if (colors[id] == color) {
                            return false;
                        }
                        if (!colors[id]) {
                            colors[id] = -color;
                            Q.push(id);
                        } 
                    }
                }
            }
        }
        return true;
    }
};
