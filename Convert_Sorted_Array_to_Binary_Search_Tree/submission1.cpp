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
        int rootindex;
        if (nums.size()%2 == 0)
        {
            rootindex = nums.size()/2-1; 
        }
        else
        {
            rootindex = nums.size()/2;
        }
        TreeNode* root = new TreeNode(nums[rootindex]);
        vector<int> leftelement(nums.begin(), nums.begin()+rootindex);
        vector<int> rightelement(nums.begin()+rootindex+1, nums.end());
        root->left = sortedArrayToBST(leftelement);
        root->right = sortedArrayToBST(rightelement);
        return root;
    }
};
