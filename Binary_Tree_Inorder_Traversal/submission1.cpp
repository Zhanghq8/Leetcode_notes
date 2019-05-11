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
        if (root == NULL) {
            return vector<int>();
        }
        Inorder(root);
        return result;
        
    }
private:
    vector<int> result;
    void Inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (root->left != NULL) {
            Inorder(root->left);
        }
        result.push_back(root->val);
        if (root->right != NULL) {
            Inorder(root->right);
        }
    }
};

