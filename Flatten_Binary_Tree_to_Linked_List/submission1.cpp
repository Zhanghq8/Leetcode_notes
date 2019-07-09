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
    void flatten(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> S;
        TreeNode* current = root;
        while (current != NULL || !S.empty())
        {
            while (current != NULL)
            {   
                result.push_back(current->val);
                S.push(current);
                current = current->left;
            }
            current = S.top();
            S.pop();
            current = current->right;
        }
        TreeNode* new_current = root;
        for (int i=1; i<result.size(); i++)
        {   
            if (new_current->left != NULL)
            {
                new_current->left = NULL;
            }
            if (new_current->right == NULL)
            {
                TreeNode* temp = new TreeNode(result[i]);
                new_current->right = temp;
            }
            new_current->right->val = result[i];
            new_current = new_current->right;
        }
    }
};