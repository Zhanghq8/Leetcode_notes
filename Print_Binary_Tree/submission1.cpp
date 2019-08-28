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
    vector<vector<string>> printTree(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        int height = get_Height(root);
        int num_nodes = pow(2, height) - 1;
        vector<vector<string>> result (height, vector<string> (num_nodes, ""));
        helper(root, 0, num_nodes - 1, height, 0, result);
        return result;
    }
private:
    int get_Height(TreeNode* node) {
        if (node == 0) {
            return 0;
        }
        return max(get_Height(node->left), get_Height(node->right)) + 1;
    }
    void helper(TreeNode* root, int left, int right, int Height, int curHeight, vector<vector<string>>& result) {
        if (curHeight == Height || root == NULL) {
            return;
        }
        result[curHeight][(left+right)/2] = to_string(root->val);
        helper(root->left, left, (left+right)/2 - 1, Height, curHeight + 1, result);
        helper(root->right, (left+right)/2 + 1, right, Height, curHeight + 1, result);
    }
};