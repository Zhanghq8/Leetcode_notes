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
    int rob(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (umap.find(root) != umap.end()) {
            return umap.find(root)->second;
        }
        int val = root->val;
        int lleft = 0;
        int lright = 0;
        int rleft = 0;
        int rright = 0;
        if (root->left) {
            lleft = rob(root->left->left); 
            lright= rob(root->left->right);
        }
        if (root->right) {
            rleft = rob(root->right->left); 
            rright= rob(root->right->right);
        }
        int result1 = val+lleft+lright+rleft+rright;
        int result2 = rob(root->left)+rob(root->right);
        umap[root] = max(result1, result2);
        return umap[root];
    }
private:
    unordered_map<TreeNode*, int> umap;
};