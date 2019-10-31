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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int length = Q.size()-1;
            vector<int> ele_samelevel;
            while (length>=0) {
                TreeNode* current = Q.front();
                if (current->left != NULL) {
                    Q.push(current->left);
                }
                if (current->right != NULL) {
                    Q.push(current->right);
                }
                ele_samelevel.push_back(current->val);
                Q.pop();
                length--;
            }
            result.push_back(ele_samelevel);
        }
        return result;
    }
};

