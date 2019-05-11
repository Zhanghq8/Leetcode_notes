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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        stack<TreeNode*> S;
        TreeNode* current = root;
        TreeNode* previous = NULL;
        while (current!= NULL || !S.empty()) {
            while (current != NULL) {
                S.push(current);
                current = current->left;
            }
            current = S.top();
            if (previous && current->val<=previous->val) {
                return false;
            }
            S.pop();
            previous = current;
            current = current->right;
        }
        return true;
    }
};
