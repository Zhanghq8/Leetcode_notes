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
            return NULL;
        }
        unordered_map<Node*, Node*> umap;
        queue<Node*> Q;
        Q.push(node);
        Node* clone = new Node(node->val);
        umap[node] = clone;
        while (!Q.empty()) {
            Node* cur = Q.front();
            Q.pop();
            for (auto neighbor : cur->neighbors) {
                if (!umap.count(neighbor)) {
                    umap[neighbor] = new Node(neighbor->val);
                    Q.push(neighbor);
                }
                umap[cur]->neighbors.push_back(umap[neighbor]);
            }
        }
        return clone;
    }
};