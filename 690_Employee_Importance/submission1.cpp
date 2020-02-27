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
        for (int i = 0; i < employees.size(); i++) {
            umap[employees[i]->id] = i; 
        }
        int result = 0;
        helper(employees, umap, id, result);
        return result;
    }
private:
    void helper(vector<Employee*>& employees, unordered_map<int, int>& umap, int id, int& result) {
        result += employees[umap[id]]->importance;
        if (employees[umap[id]]->subordinates.empty()) {
            return;
        }
        for (int i = 0; i < employees[umap[id]]->subordinates.size(); i++) {
            helper(employees, umap, employees[umap[id]]->subordinates[i], result);
        }
    }
};
