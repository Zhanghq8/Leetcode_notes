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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> pre2in;
        for (int i = 0;i < inorder.size(); i++) {
            pre2in[inorder[i]] = i;
        }
        return buildSubtree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, pre2in);
    }
private:
    TreeNode* buildSubtree(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie,                         unordered_map<int, int>& pre2in) {
        if (ps > pe || is > ie) {
            return nullptr;
        }
        int inorderMiddle = pre2in[preorder[ps]];
        int preorderMiddle = ps + (inorderMiddle - is);
        TreeNode* cur = new TreeNode(preorder[ps]);
        cur->left = buildSubtree(preorder, ps + 1, preorderMiddle, inorder, is, inorderMiddle-1, pre2in);
        cur->right = buildSubtree(preorder, preorderMiddle + 1, pe, inorder, inorderMiddle + 1, ie, pre2in);
        return cur;
    }
};