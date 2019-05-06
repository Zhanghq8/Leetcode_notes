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
        if (root == NULL)
        {
            return true;
        }
        int diffh = diffheight(root);
        if (diffh == -1)
        {
            return false;
        }
        return true;
    }
    int diffheight(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftheight = diffheight(root->left);
        int rightheight = diffheight(root->right);
        int diff = abs(leftheight - rightheight);
        if (leftheight == -1 || rightheight == -1)
        {
            return -1;
        }
        if (diff > 1)
        {
            return -1;
        }
        return max(leftheight, rightheight)+1;
    }
};

