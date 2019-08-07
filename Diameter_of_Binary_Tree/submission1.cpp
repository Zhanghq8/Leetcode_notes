// Selection sort
#include <iostream>
#include <vector>
#include <stack>

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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int lheight = depth(root->left);
        int rheight = depth(root->right);
        int result = lheight + rheight;
        return max(result, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
private:
    int depth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int ldepth = depth(root->left);
        int rdepth = depth(root->right);
        int result = max(ldepth, rdepth) + 1;
        return result;
    }
};

