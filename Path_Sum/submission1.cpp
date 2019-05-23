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
        if (root == NULL && sum != 0) {
            return false;
        }
        if (root == NULL && sum == 0) {
            return false;
        }
        return hasSum(root, sum-root->val);
    }
private:
    bool hasSum(TreeNode* root, int sum) {
        if ((root->left == NULL && root->right == NULL) && sum == 0) {
            return true;
        }
        bool leftsum = false;
        bool rightsum = false;
        if (root->left != NULL) {
            leftsum = hasSum(root->left, sum-root->left->val);
        }
        if (root->right != NULL) {
            rightsum = hasSum(root->right, sum-root->right->val);
        }
        return (leftsum == true || rightsum == true);
    }
};
