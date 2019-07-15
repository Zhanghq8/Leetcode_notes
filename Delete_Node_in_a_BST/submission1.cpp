#include <iostream>
#include <string>
#include <cmath>

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return root;
        }
        else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (root->left == NULL && root->right == NULL) {
                root = NULL;
            }
            else if (root->left == NULL) {
                TreeNode* next = root;
                root = next->right;
            }
            else if (root->right == NULL) {
                TreeNode* next = root;
                root = next->left; 
            }
            else {
                TreeNode* submin = root->right;
                while (submin->left != NULL) {
                    submin = submin->left;
                }
                root->val = submin->val;
                root->right = deleteNode(root->right, submin->val);
            }
        }
        return root;
    }
};
