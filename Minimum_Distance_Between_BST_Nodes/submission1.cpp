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
    int minDiffInBST(TreeNode* root) {
        int result = INT_MAX;
        int pre_num = -1;
        Inorder(root, pre_num, result);
        return result;
    }
private:
    void Inorder(TreeNode* node, int& pre_num, int& result) {
        if (node == NULL) {
            return;
        }
        Inorder(node->left, pre_num, result);
        if (pre_num != -1) {
            result = min(result, node->val - pre_num);
        }
        pre_num = node->val;
        Inorder(node->right, pre_num, result);
    }
};