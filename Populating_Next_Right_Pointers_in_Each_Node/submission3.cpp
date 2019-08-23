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
        Node* start = root;
        Node* current = NULL;
        while (start->left != NULL) {
            current = start;
            while (current != NULL) {
                current->left->next = current->right;
                if (current->next != NULL) {
                    current->right->next = current->next->left;
                }
                current = current->next;
            }
            
            start = start->left;
        }
        return root;
    }
};