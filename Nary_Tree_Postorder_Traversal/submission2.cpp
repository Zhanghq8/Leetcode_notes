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
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        stack<Node*> S;
        S.push(root);
        while (!S.empty()) {
            Node* current = S.top();
            S.pop();
            for (auto n:current->children) {
                S.push(n);
            }
            result.push_back(current->val);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

