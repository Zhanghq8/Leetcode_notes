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
    int findTilt(TreeNode* root) {
        int tilt = 0;
        helper(root, tilt);
        return tilt;
    }
    int helper(TreeNode* root, int& tilt) {
        if (!root) {
            return 0;
        }
        int left = helper(root->left, tilt);;
        int right = helper(root->right, tilt);
        tilt += abs(left - right);
        return left + right + root->val;
    }
};