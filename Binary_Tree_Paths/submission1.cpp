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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root != NULL) {
            helper(root, "", result);
        }
        return result;
    }
private:
    void helper(TreeNode* root, string output, vector<string>& result) {
        if (root->left == NULL && root->right == NULL) {
            result.push_back(output + to_string(root->val));
            return;
        }
        if (root->left != NULL) {
            helper(root->left, output + to_string(root->val) + "->", result);
        }
        if (root->right != NULL) {
            helper(root->right, output + to_string(root->val) + "->", result);
        }
    }
};
