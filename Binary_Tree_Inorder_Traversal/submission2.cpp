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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> S;
        TreeNode* current = root;
        while (current != NULL || !S.empty()) {
            while (current != NULL) {
                S.push(current);
                current = current->left;
            }
            current = S.top();
            S.pop();
            result.push_back(current->val);
            current = current->right;
        }
        return result;
    }
};

