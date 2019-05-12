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
    int maxDepth(Node* root) {
        if (root == NULL) {
            return 0;
        }
        queue<Node*> Q;
        Node* current = root;
        Q.push(current);
        int depth = 0;
        while (!Q.empty()) {
            int length = Q.size();    
            for (int i=0; i<length; i++) {
                current = Q.front();
                for (auto n:current->children) {
                    Q.push(n);
                }
                Q.pop();
            }
            depth++;
        } 
        return depth;
    }
};

