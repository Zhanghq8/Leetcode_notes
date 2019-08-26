#include <iostream>
#include <string>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        } 
        queue<Node*> Q;
        Q.push(root);   
        while (Q.empty() != true) {
            int length = Q.size() - 1;
            while (length >= 0) {
                Node* current = Q.front();
                Q.pop();
                if (length != 0) {
                    current->next = Q.front();
                }
                if (current->left != NULL) {
                    Q.push(current->left);
                }
                if (current->right != NULL) {
                    Q.push(current->right);
                }
                length--;
            }
        }
        return root;
    }
};