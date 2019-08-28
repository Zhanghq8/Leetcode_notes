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
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int length = Q.size()-1;
            
            while (length>=0) {
                TreeNode* current = Q.front();
                if (current->left != NULL) {
                    Q.push(current->left);
                }
                if (current->right != NULL) {
                    Q.push(current->right);
                }
                result.push_back(current->val);
                Q.pop();
                length--;
            }
        }
        int min = result[0];
        sort(result.begin(), result.end());
        for (int i=0; i<result.size(); i++) {
            if (result[i] > min) {
                return result[i];
            }
        }
        return -1;
    }
};