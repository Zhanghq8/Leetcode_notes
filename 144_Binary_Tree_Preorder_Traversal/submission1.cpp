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
        dfs(root, result);
        return result;
    }
private:
    void dfs(TreeNode* root, vector<int>& result) {
        if (root == NULL) {
            return;
        }
        result.push_back(root->val);
        if (root->left != NULL) {
            dfs(root->left, result);
        }
        if (root->right != NULL) {
            dfs(root->right, result);
        }
    }
};

