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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelorder(root, result, 0);
        return result;
    }
private:
    
    void levelorder(TreeNode* root, vector<vector<int>>& element, int level) {
        if (root == NULL) {
            return;
        }
        if (level == element.size()) {
            element.push_back(vector<int>());    
        }
        element[level].push_back(root->val);
        levelorder(root->left, element, level+1);
        levelorder(root->right, element, level+1);
    }
    
};
