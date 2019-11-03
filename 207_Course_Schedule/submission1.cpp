#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int> ());
        vector<int> indegree(numCourses, 0);
        for (auto n : prerequisites) {
            graph[n[1]].push_back(n[0]);
            indegree[n[0]]++;
        }
        queue<int> Q;
        for (int i=0; i<indegree.size(); i++) {
            if (indegree[i] == 0) {
                Q.push(i);
            }
        }
        while (!Q.empty()) {
            int index = Q.front();
            Q.pop();
            for (auto temp : graph[index]) {
                indegree[temp]--;
                if (indegree[temp] == 0) {
                    Q.push(temp);
                }
            }
        }
        for (int i=0; i<numCourses; i++) {
            if (indegree[i] != 0) {
                return false;
            }
        } 
        return true;
    }
};