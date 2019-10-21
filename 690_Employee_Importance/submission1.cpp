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
        map<int, Employee*> info;
        for (int i=0; i<employees.size(); i++) {
            info[employees[i]->id] = employees[i];
        }
        int imp = 0;
        dfs(employees, info, id, imp);
        return imp;
    }
private:
    void dfs(vector<Employee*>& employees, map<int, Employee*>& info, int id, int &imp) {
        map<int, Employee*>::iterator target = info.find(id);
        if (target->second->subordinates.size() == 0) {
            imp += target->second->importance;
            return;
        }
        imp += target->second->importance;
        for (int i=0; i<target->second->subordinates.size(); i++) {
            map<int, Employee*>::iterator sub = info.find(target->second->subordinates[i]);
            dfs(employees, info, sub->second->id,imp);
        }
    }
};
