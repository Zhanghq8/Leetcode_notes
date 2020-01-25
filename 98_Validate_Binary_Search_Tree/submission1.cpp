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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        return helper(root, LONG_MIN, LONG_MAX);
    }
private:
    bool helper(TreeNode* root, long minVal, long maxVal) {
        if (!root) {
            return true;
        }
        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }
        return helper(root->left, minVal, root->val) && helper(root->right, root->val, maxVal);
    }
};