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
        if (root == NULL) {
            return -1;
        }
        bool flag = false;
        int first_min = root->val;
        int second_min = INT_MAX; 
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            TreeNode* current = Q.front();
            if (current->val != first_min && current->val <= second_min) {
                second_min = current->val;
                flag = true;
            }
            if (current->left != NULL) {
                Q.push(current->left);
            }
            if (current->right != NULL) {
                Q.push(current->right);
            }
            Q.pop();
        }
        if (second_min == first_min || flag == false) {
            return -1;
        }
        return second_min;
    }
};