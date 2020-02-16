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
        unordered_map<int, int> umap;
        umap[0] = 1;
        helper(root, sum, 0, umap, result);
        return result;
    }
private:
    void helper(TreeNode* root, int sum, int curSum, unordered_map<int, int>& umap, int& result) {
        if (!root) {
            return;
        }
        curSum += root->val;
        result += umap[curSum - sum];
        umap[curSum]++;
        helper(root->left, sum, curSum, umap, result);
        helper(root->right, sum, curSum, umap, result);
        umap[curSum]--;
    }
};