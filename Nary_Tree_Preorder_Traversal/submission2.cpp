#include <iostream>
#include <string>

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
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        stack<Node*> S;
        S.push(root);
        while (!S.empty()) {
            Node* current = S.top();
            S.pop();            
            result.push_back(current->val); 
            for (int i=current->children.size()-1; i>=0; i--) {
                S.push(current->children[i]);
            }
        }
        return result;
    }
};

