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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        stack<TreeNode*> S;
        TreeNode* current = root;
        while (!S.empty() || current != NULL) {
            while (current) {
                result.push_back(current->val);
                S.push(current);
                current = current->left;
            }
            current = S.top();
            S.pop();
            current = current->right;
        }
        return result;
    }
};
