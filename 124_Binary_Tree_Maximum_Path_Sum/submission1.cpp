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

// Expect: left subtree max sum from current root node, and right subtree max sum from current root node
// Current layer opeation: update globalMax with the max among the value from current node itself, current 
// node + left subtree max sum and current node + right subtree max sum
// Report to parent: max among the value from current node itself, current  node + left subtree max sum and 
// current node + right subtree max sum

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN;
        helper(root, globalMax);
        return globalMax;
    }
private:
    int helper(TreeNode* root, int& globalMax) {
        if (!root) {
            return 0;
        }
        int leftMax = helper(root->left, globalMax);
        int rightMax = helper(root->right, globalMax);
        globalMax = max(max(0, leftMax) + max(0, rightMax) + root->val, globalMax);
        return max(max(0, leftMax), max(0, rightMax)) + root->val;
    }
};