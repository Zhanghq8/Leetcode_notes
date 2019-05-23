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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        int temp = sum - root->val;
        if (root->left == NULL && root->right == NULL && temp == 0) {
            return true;
        }
        return (hasPathSum(root->left, temp) || hasPathSum(root->right, temp));
    }
};
