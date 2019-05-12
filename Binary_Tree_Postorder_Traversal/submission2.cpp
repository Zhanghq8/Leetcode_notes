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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        stack<TreeNode*> S;
        S.push(root);
        while (!S.empty()) {
            TreeNode* current = S.top();
            S.pop();
            if (current->left != NULL) {
                S.push(current->left);
            }
            if (current->right != NULL) {
                S.push(current->right);
            }
            result.push_back(current->val);      
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

