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
        TreeNode* cur = root;
        while (cur != NULL || !S.empty()) {
            while (cur != NULL) {
                S.push(cur);
                cur = cur->left;
            }
            cur = S.top();
            result.push_back(cur->val);
            S.pop();
            cur = cur->right;
        }
        return result;
    }
};

