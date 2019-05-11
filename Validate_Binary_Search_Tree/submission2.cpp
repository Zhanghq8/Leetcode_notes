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
        if (root == NULL) {
            return true;
        }
        if (isSubtreeLesser(root->left, root->val) && isSubtreeGreater(root->right, root->val) && isValidBST(root->left) && isValidBST(root->right)) {
            return true;
        }
        else {
            return false;
        }
    }
private:
    bool isSubtreeLesser(TreeNode* root, int value) {
        if (root == NULL) {
            return true;
        }
        if (root->val<value && isSubtreeLesser(root->left, value) && isSubtreeLesser(root->right, value)) {
            return true;
        }
        else {
            return false;
        }
    }
    bool isSubtreeGreater(TreeNode* root, int value) {
        if (root == NULL) {
            return true;
        }
        if (root->val>value && isSubtreeGreater(root->left, value) && isSubtreeGreater(root->right, value)) {
            return true;
        }
        else {
            return false;
        }
    }
};
