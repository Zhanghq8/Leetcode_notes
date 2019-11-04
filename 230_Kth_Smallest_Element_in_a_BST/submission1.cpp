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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur = root;
        int count = 0;
        stack<TreeNode*> S;
        while (!S.empty() || cur) {
            while (cur) {
                S.push(cur);
                cur = cur->left;
            }
            cur = S.top();
            S.pop();
            count++;
            if (count == k) {
                return cur->val;
            }
            cur = cur->right;
        }
        return 0;
    }
};
