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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        if (root == NULL) {
            return sum;
        }
        stack<TreeNode*> S;
        TreeNode* current = root;
        while (current != NULL || S.empty() != true) {
            while (current != NULL) {
                S.push(current);
                current = current->left;                
            }
            current = S.top();
            if (current-> val >= L && current->val <= R) {
                sum += current->val;
            }
            else if (current->val > R) {
                break;
            }
            S.pop();
            current = current->right;
        }
        return sum;
    }
};