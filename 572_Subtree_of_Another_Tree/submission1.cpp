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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!t) {
            return true;
        }
        if (!s) {
            return false;
        }
        if (isSameTree(s, t)) {
            return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
private:
    bool isSameTree(TreeNode* one, TreeNode* two) {
        if (!one && !two) {
            return true;
        }
        if (!one || !two) {
            return false;
        }
        return one->val == two->val && isSameTree(one->left, two->left) && isSameTree(one->right, two->right);
    }
};