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
    vector<int> postorderTraversal(TreeNode* root) {
        postorder_element(root);
        return result;
    }
private:
    vector<int> result;
    void postorder_element(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        postorder_element(root->left);
        postorder_element(root->right);
        result.push_back(root->val);
    }
};

