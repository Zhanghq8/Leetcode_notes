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
        insert(root, 0);
        reverse(result.begin(), result.end());
        return result;
    }
private:
    vector<vector<int>> result;
    void insert(TreeNode* root, int height) {
        if (root == NULL)
        {
            return;
        }
        while (result.size()<=height) {
            result.push_back(vector<int>());
        }
        result[height].push_back(root->val);
        insert(root->left,  height+1);
        insert(root->right, height+1);
    }
};