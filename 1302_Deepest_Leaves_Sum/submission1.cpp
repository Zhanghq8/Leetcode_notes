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
    int deepestLeavesSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int sum = 0;
        queue<TreeNode*> Q;
        TreeNode* cur = root;
        Q.push(cur);
        while (!Q.empty()) {
            sum = 0;
            for (int i = Q.size(); i > 0; i--) {
                TreeNode* temp = Q.front();
                Q.pop();
                sum += temp->val;
                if (temp->left) {
                    Q.push(temp->left);
                }
                if (temp->right) {
                    Q.push(temp->right);
                }
            }
        }
        return sum;
    }
};