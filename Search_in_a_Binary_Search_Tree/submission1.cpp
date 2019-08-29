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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* current = root;
        stack<TreeNode*> S;
        while (current != NULL || S.empty() != true) {
            while (current != NULL) {
                S.push(current);
                current = current->left;
            }
            current = S.top();
            S.pop();
            if (current->val == val) {
                return current;
            }
            else {
                current = current->right;
            }
        }
        return NULL;
    }
};