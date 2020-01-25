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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        TreeNode* pre = nullptr;
        stack<TreeNode*> data;
        TreeNode* cur = root;
        while (!data.empty() || cur) {
            while (cur) {
                data.push(cur);
                cur = cur->left;
            }
            cur = data.top();
            if (pre && pre->val >= cur->val) {
                return false;
            }
            pre = cur;
            data.pop();
            cur = cur->right;
        }
        return true;
    }
};