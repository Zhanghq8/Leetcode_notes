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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> post2in;
        for (int i = 0; i < inorder.size(); i++) {
            post2in[inorder[i]] = i;
        }
        return buildSubtree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, post2in);
    }
private:
    TreeNode* buildSubtree(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe,                         unordered_map<int, int>& post2in) {
        if (is >ie || ps > pe) {
            return nullptr;
        }
        int inorderMiddle = post2in[postorder[pe]];
        int postorderMiddle = ps + (inorderMiddle - is) - 1;
        TreeNode* cur = new TreeNode(postorder[pe]);
        cur->left = buildSubtree(inorder, is, inorderMiddle - 1, postorder, ps, postorderMiddle, post2in);
        cur->right = buildSubtree(inorder, inorderMiddle + 1, ie, postorder, postorderMiddle + 1, pe - 1, post2in);
        return cur;
    }
};