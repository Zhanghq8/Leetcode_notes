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
        addsolution(result, output, root, sum);
        return result;
    }
private:
    void addsolution(vector<vector<int>>& result, vector<int>& output, TreeNode* root, int sum) {
        if (root == NULL) {
            return;
        }
        output.push_back(root->val);
        int temp = sum - root->val;
        if (root->left == NULL && root->right == NULL && temp == 0) {
            result.push_back(output);
        }
        addsolution(result, output, root->left, temp);
        addsolution(result, output, root->right, temp);
        output.pop_back();
    }
};
