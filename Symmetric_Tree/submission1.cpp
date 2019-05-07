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
    bool isSymmetric(TreeNode* root) {
        return isNodeSymmetric(root, root);
    }
private:
    bool isNodeSymmetric(TreeNode* t1, TreeNode* t2)
    {
        if ( (t1 == NULL && t2 != NULL) or (t1 != NULL && t2 == NULL) )
        {
            return false;
        }
        if (t1 == NULL && t2 == NULL)
        {
            return true;
        }
        return ( (t1->val == t2->val) && isNodeSymmetric(t1->left, t2->right) && isNodeSymmetric(t1->right, t2->left) );  
    }
};
