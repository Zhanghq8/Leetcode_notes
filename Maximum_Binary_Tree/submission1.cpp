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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }
        int max_num = INT_MIN;
        int index;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > max_num) {
                max_num = nums[i];
                index = i;
            }
        }
        TreeNode* newnode = new TreeNode(max_num);
        vector<int> leftarr = vector<int> (nums.begin(), nums.begin() + index);
        vector<int> rightarr = vector<int> (nums.begin() + index + 1, nums.end());
        newnode->left = constructMaximumBinaryTree(leftarr);
        newnode->right = constructMaximumBinaryTree(rightarr);
        return newnode;
    }
};