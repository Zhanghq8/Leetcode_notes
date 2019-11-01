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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pl = 0, il = 0;
        int pr = preorder.size()-1, ir = inorder.size()-1;
        return dfs(preorder, pl, pr, inorder, il, ir);
    }
private:
    TreeNode* dfs(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir) {
        if (pl > pr || il > ir) {
            return NULL;
        }
        int i = 0;
        for (i=il; i<=ir; i++) {
            if (preorder[pl] == inorder[i]) {
                break;
            }
        }
        TreeNode* cur = new TreeNode(preorder[pl]);
        cur->left = dfs(preorder, pl+1, pl+i-il, inorder, il, i-1);
        cur->right = dfs(preorder, pl+i-il+1, pr, inorder, i+1, ir);
        return cur;
    }
};