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
    int pathSum(TreeNode* root, int sum) {
        int result = 0;
        vector<TreeNode*> output;
        helper(root, 0, sum, output, result);
        return result;
    }
private:
    void helper(TreeNode* root, int curSum, int sum, vector<TreeNode*>& output, int& result) {
        if (!root) {
            return;
        }
        curSum += root->val;
        output.push_back(root);
        if (curSum == sum) {
            result++;
        }
        int temp = curSum;
        for (int i = 0; i < output.size() - 1; i++) {
            temp -= output[i]->val;
            if (temp == sum) {
                result++;
            }
        }
        helper(root->left, curSum, sum, output, result);
        helper(root->right, curSum, sum, output, result);
        output.pop_back();
    }
};