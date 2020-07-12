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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        queue<TreeNode*> element_level;
        element_level.push(root);
        while (!element_level.empty()) {
            vector<int> ele_sameheight;
            int length = element_level.size()-1;
            while (length>=0) {
                TreeNode* current = element_level.front();
                ele_sameheight.push_back(current->val);
                    if (current->left != NULL) {
                        element_level.push(current->left);
                    }
                    if (current->right != NULL) {
                        element_level.push(current->right);
                    }
                element_level.pop();
                length--;
            }
            result.push_back(ele_sameheight);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
