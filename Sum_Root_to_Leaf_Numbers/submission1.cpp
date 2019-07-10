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
    int sumNumbers(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        int result = 0;
        stack<TreeNode*> S;
        S.push(root);
        while (!S.empty())
        {
            TreeNode* current = S.top();
            S.pop();
            if (!current->left && !current->right)
            {
                result += current->val;
            }
            if (current->left)
            {
                current->left->val += current->val * 10;
                S.push(current->left);
            }
            if (current->right)
            {
                current->right->val += current->val * 10;
                S.push(current->right);
            }
        }
        return result;
    }
};

