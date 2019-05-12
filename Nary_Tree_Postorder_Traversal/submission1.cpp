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
        post_element(root, result);
        return result;

    }
private:
    void post_element(Node* root, vector<int>& result) {
        if (root == NULL) {
            return;
        }
        for (auto n:root->children) {
            post_element(n, result);
        }
        result.push_back(root->val);
    }
};

