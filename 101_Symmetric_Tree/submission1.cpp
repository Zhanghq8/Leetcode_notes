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
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isSame(root->left, root->right);
    }
private:
    bool isSame(TreeNode* leftTree, TreeNode* rightTree) {
        if (!leftTree && !rightTree) {
            return true;
        }
        if (!leftTree || !rightTree) {
            return false;
        }
        if (leftTree->val != rightTree->val) {
            return false;
        }
        return isSame(leftTree->left, rightTree->right) && isSame(leftTree->right, rightTree->left);
    }
};