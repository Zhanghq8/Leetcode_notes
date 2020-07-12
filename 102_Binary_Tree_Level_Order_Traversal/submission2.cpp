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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        int level = 1;
        helper(result, level, root);
        return result;
    }
    void helper(vector<vector<int>>& result, int level, TreeNode* root) {
        if (!root) {
            return;
        }
        if (level > result.size()) {
            result.push_back({root->val});
        } else {
            result[level - 1].push_back(root->val);
        }
        helper(result, level + 1, root->left);
        helper(result, level + 1, root->right);
    }
};
