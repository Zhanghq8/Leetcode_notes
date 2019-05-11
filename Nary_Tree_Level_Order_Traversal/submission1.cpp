#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        queue<Node*> Q;
        Q.push(root);
        while (!Q.empty()) {
            vector<int> ele_samelevel;
            int length = Q.size();
            for (int i=0; i<length; i++) {
                Node* current = Q.front();
                ele_samelevel.push_back(current->val);
                Q.pop();
                for (auto child:current->children) {
                    Q.push(child);
                }
            }
            result.push_back(ele_samelevel);
        }
        return result;
    }
};

