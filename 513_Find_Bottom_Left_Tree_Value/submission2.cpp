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
    int findBottomLeftValue(TreeNode* root) {
        int result = root->val;
        int maxLevel = 1;
        helper(root, 1, maxLevel, result);
        return result;
    }
private:
    void helper(TreeNode* root, int curLevel, int& maxLevel, int& result) {
        if (!root) {
            return;
        }
        if (curLevel > maxLevel) {
            maxLevel = curLevel;
            result = root->val;
        }
        helper(root->left, curLevel+1, maxLevel, result);
        helper(root->right, curLevel+1, maxLevel, result);
    }
};
