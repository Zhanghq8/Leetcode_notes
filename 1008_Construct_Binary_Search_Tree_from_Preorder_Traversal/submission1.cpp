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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = buildTree(preorder, 0, preorder.size());
        return root;
    }
private:
    TreeNode* buildTree(vector<int>& preorder, int num, int index) {
        if (num >= index) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[num]);
        int start = num;
        while (start < index && preorder[start] <= root->val) {
            start++;
        }
        root->left = buildTree(preorder, num + 1, start);
        root->right = buildTree(preorder, start, index);
        return root;
    }
};