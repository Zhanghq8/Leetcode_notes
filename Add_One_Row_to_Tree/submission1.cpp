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
        if (d == 0 || d == 1) {
            TreeNode* newnode = new TreeNode(v);
            if (d == 1) {
                newnode->left = root;    
            }
            else {
                newnode->right = root;
            }
            return newnode;
        }
        if (root != NULL && d > 1) {
            if (d > 2) {
                root->left = addOneRow(root->left, v, d - 1);
                root->right = addOneRow(root->right, v, d - 1);
            }
            else {
                root->left = addOneRow(root->left, v, 1);
                root->right = addOneRow(root->right, v, 0);
            }            
        }
        return root;
    }
};