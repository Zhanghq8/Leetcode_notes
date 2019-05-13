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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == NULL) {
            return vector<double>();
        }
        vector<double> result;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int count = 0;
            double element = 0;
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
                element += current->val; 
                count++;
                length--;
            }
            element = element/count;
            result.push_back(element);
        }
        return result;
    }
};
