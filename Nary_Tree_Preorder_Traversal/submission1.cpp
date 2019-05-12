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
        pre_element(root, result);
        return result;

    }
private:
    void pre_element(Node* root, vector<int>& result) {
        if (root == NULL) {
            return;
        }
        result.push_back(root->val);
        for (auto n:root->children) {
            pre_element(n, result);
        }
    }
};

