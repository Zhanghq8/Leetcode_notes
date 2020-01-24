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
    bool isBalanced(TreeNode* root) {
        if (checkDepth(root) == -1) {
            return false;
        }
        return true;
    }
private:
    int checkDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftHeight = checkDepth(root->left);
        if (leftHeight == -1) {
            return -1;
        }
        int rightHeight = checkDepth(root->right);
        if (rightHeight == -1) {
            return -1;
        }
        int diff = abs(leftHeight - rightHeight);
        if (diff > 1) {
            return -1;
        } else {
            return max(leftHeight, rightHeight) + 1;
        }
        
    }
};
