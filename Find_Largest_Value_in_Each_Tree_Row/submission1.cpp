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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        int max_value= INT_MIN;
        if (root == NULL) {
            return result;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int length = Q.size();
            for (int i=0; i<length; i++) {
                TreeNode* current = Q.front();
                if (max_value < current->val) {
                    max_value = current->val;
                }
                if (current->left != NULL) {
                    Q.push(current->left);
                }
                if (current->right != NULL) {
                    Q.push(current->right);
                }
                Q.pop();
            }
            result.push_back(max_value);
            max_value= INT_MIN;
        }
        return result;
    }
};
