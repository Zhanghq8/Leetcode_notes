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
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        int count = 0;
        while (!Q.empty()) {
            int length = Q.size()-1;
            while (length>=0) {
                TreeNode* current = Q.front();
                Q.pop();
                if (current->left != NULL) {
                    Q.push(current->left);
                }
                if (current->right != NULL) {
                    Q.push(current->right);
                }
                count++;
                length--;
            }
        }
        return count;
    }
};

