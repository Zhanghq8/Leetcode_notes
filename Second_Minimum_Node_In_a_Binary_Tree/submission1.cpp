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
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return 0;
        }
        int first_min = root->val;
        int second_min = INT_MAX; 
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            TreeNode* current = Q.front();
            if (current->val > first && current->val < second) {
                return current->val;
            }
            if (current->left != NULL) {
                Q.push(current->left);
            }
            if (current->right != NULL) {
                Q.push(current->right);
            }
            Q.pop();
        }
        return -1;
    }
};