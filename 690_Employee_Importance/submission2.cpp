#include <iostream>
#include <string>

using namespace std;

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        if (employees.empty()) {
            return 0;
        }
        unordered_map<int, int> umap;
        for(int i = 0; i < employees.size(); i++) {
            umap[employees[i]->id] = i;
        }
        queue<int> Q;
        Q.push(id);
        int result = 0;
        while (!Q.empty()) {
            int idTemp = Q.front();
            result += employees[umap[idTemp]]->importance;
            Q.pop();
            for (int idNext : employees[umap[idTemp]]->subordinates) {
                Q.push(idNext);
            }
        }
        return result;
    }
};
