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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int depthX = -1;
        int depthY = -1;
        TreeNode* pX = nullptr;
        TreeNode* pY = nullptr;
        pX = getP(root, x, 0, depthX);
        pY = getP(root, y, 0, depthY);
        return pX != pY && depthX == depthY;
    }
private:
    TreeNode* getP(TreeNode* root, int value, int level, int& depth) {
        if (!root) {
            return nullptr;
        }
        TreeNode* parent = nullptr;
        if ((root->left && root->left->val == value) || (root->right && root->right->val == value)) {
            depth = level;
            return root;
        }
        TreeNode* left = getP(root->left, value, level + 1, depth);
        if (left) {
            return left;
        }
        TreeNode* right = getP(root->right, value, level + 1, depth);
        if (right) {
            return right;
        }
        return nullptr;      
    }
};