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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return NULL;            
        }
        return buildTree(nums, 0, nums.size()-1);
    }
private:
    TreeNode* buildTree(vector<int> nums, int start_index, int end_index)
    {   
        if (start_index > end_index)
        {
            return NULL;
        }
        int mid_index = (start_index+end_index)/2;
        TreeNode* root = new TreeNode(nums[mid_index]);
        root->left = buildTree(nums, start_index, mid_index-1);
        root->right = buildTree(nums, mid_index+1, end_index);
        return root;
        
    }
};
