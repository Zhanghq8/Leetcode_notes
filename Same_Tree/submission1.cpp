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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p == NULL and q != NULL) || ((q == NULL and p != NULL))) {
            return false;
        }
        if (p == NULL and q == NULL) {
            return true;
        }
        if (p->val != q->val) {
            return false;
        }
        bool result;
        if (isSameTree(p->left, q->left) == true && isSameTree(p->right, q->right) == true) {
            result = true;
        }
        else {
            result = false;
        }
        return result;
    }
};