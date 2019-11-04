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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return helper(root, k, count);
    }
private:
    int helper(TreeNode* root, int k, int& count) {
        if (root == NULL) {
            return -1;
        }
        int value = helper(root->left, k, count);
        if (count == k) {
            return value;
        }
        if (++count == k) {
            return root->val;
        }
        return helper(root->right, k, count);
    }
};