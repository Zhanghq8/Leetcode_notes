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
        preorder_element(root);
        return preorder;
    }
private:
    vector<int> preorder;
    void preorder_element(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        preorder.push_back(root->val);
        preorder_element(root->left);
        preorder_element(root->right);
    }
};

