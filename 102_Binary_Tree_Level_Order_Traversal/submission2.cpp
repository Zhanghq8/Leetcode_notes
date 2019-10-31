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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int max_depth = -1;
        dfs(root, 0, max_depth, result);
        return result;
    }
private: 
    void dfs(TreeNode* root, int depth, int& max_depth, vector<vector<int>>& result) {
        if (root == NULL) {
            return;
        }
        if (depth > max_depth) {
            max_depth = depth;
            result.push_back({root->val});
        }
        else {
            result[depth].push_back(root->val);
        }
        dfs(root->left, depth+1, max_depth, result);
        dfs(root->right, depth+1, max_depth, result);
    }
};
