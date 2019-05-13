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
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        vector<int> result;
        result = inorder_element(root, result);
        TreeNode* newroot = new TreeNode(result[0]);
        TreeNode* current = newroot;
        for (int i=1; i<result.size(); i++) {
            current->right = new TreeNode(result[i]);
            current = current->right;
        }
        return newroot;
    }
private:
    vector<int> inorder_element(TreeNode* root, vector<int> inorder) {
        if (root == NULL) {
            return vector<int>();
        }
        stack<TreeNode*> S;
        TreeNode* current = root;
        while (!S.empty() || current) {
            while (current) {
                S.push(current);
                current = current->left;
            }
            current = S.top();
            S.pop();
            inorder.push_back(current->val);
            current = current->right;
        }
        return inorder;
    }
};

