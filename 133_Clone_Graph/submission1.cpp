#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return node;
        }
        unordered_map<Node*, Node*> umap;
        return dfs(node, umap);
    }
private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& umap) {
        if (umap.count(node)) {
            return umap[node];
        }
        Node* clone = new Node(node->val, {});
        umap[node] = clone;
        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor,umap));
        }
        return clone;
    }
};