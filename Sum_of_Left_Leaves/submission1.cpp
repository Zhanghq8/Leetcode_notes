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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }
        int sum = 0;
        queue<TreeNode*> element;
        element.push(root);
        while (!element.empty())
        {
            TreeNode* current = element.front();
            if (current->left != NULL)
            {
                element.push(current->left);
                if (current->left->left == NULL && current->left->right == NULL)
                {
                    sum += current->left->val;
                }
            }
            if (current->right != NULL)
            {
                element.push(current->right);
            }

            element.pop();
        }
        return sum;
    }
};
