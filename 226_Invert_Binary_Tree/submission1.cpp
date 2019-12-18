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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        TreeNode* leftTree = invertTree(root->left);
        TreeNode* rightTree = invertTree(root->right);
        root->left = rightTree;
        root->right = leftTree;
        return root;
    }
};