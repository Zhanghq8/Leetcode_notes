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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> output;
        helper(root, output, result, sum);
        return result;
    }
private:
    void helper(TreeNode* root, vector<int>& output, vector<vector<int>>& result, int sum) {
        if (!root) {
            return;
        }
        int temp = sum - root->val;
        output.push_back(root->val);
        if (!(root->left) && !(root->right) && !temp) {
            result.emplace_back(output);
        }
        helper(root->left, output, result, temp);
        helper(root->right, output, result, temp);
        output.pop_back();
    }
};
