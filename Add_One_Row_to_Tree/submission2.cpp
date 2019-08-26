#include <iostream>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (root == NULL) {
            return NULL;
        }
        if (d == 0 || d == 1) {
            TreeNode* newnode = new TreeNode(v);
            newnode->left = root;
            return newnode;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        while (Q.empty() != true) {
            d--;
            if (d == 0) {
                return root;
            }
            int length = Q.size();
            TreeNode* current;
            while (length > 0) {
                current = Q.front();
                if (d == 1) {
                    TreeNode* left = current->left;
                    TreeNode* right = current->right;
                    current->left = new TreeNode(v);
                    current->right = new TreeNode(v);
                    current->left->left = left;
                    current->right->right = right;
                }
                else {
                    if (current->left != NULL) {
                        Q.push(current->left);
                    }
                    if (current->right != NULL) {
                        Q.push(current->right);
                    }
                }
                Q.pop();
                length--;
            }
        }
        return root;
    }
};