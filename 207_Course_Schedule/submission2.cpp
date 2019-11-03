#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int> ());
        for (auto n : prerequisites) {
            graph[n[1]].push_back(n[0]);
        }
        vector<bool> todo(numCourses, false);
        vector<bool> done(numCourses, false);
        for (int i=0; i<numCourses; i++) {
            if (!done[i] && !acyclic(graph, todo, done, i)) {
                return false;
            }
        }
        return true;
    }
private:
    bool acyclic(vector<vector<int>>& graph, vector<bool>& todo, vector<bool>& done, int node) {
        if (todo[node]) {
            return false;
        }
        if (done[node]) {
            return true;
        }
        todo[node] = true;
        done[node] = true;
        for (auto n : graph[node]) {
            if (!acyclic(graph, todo, done, n)) {
                return false;
            }
        }
        todo[node] = false;
        return true;
    }
};