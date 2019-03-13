#include <iostream>
#incluede <math.h>
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
    int minDepth(TreeNode* root) {
        int result;
        if (root == NULL) {
            return 0;
        }
        int hleft = minDepth(root->left);
        int hright = minDepth(root->right);
        if (min(hleft, hright) == 0) {
            result = max(hleft, hright) +1;
        }
        else {
            result = min(hleft, hright) +1;
        }
        return result;
    }
};

