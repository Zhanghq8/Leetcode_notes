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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        while (Q.empty() == false) {
            int length = Q.size();
            while (length > 0) {
                TreeNode* current = Q.front();
                if (length == 1) {
                    result.push_back(current->val);
                }
                if (current->left != NULL) {
                    Q.push(current->left);
                }
                if (current->right != NULL) {
                    Q.push(current->right);
                }
                Q.pop();
                length--;
            }
        }
        return result;
    }
};

