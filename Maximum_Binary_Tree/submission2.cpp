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
        return helper(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* helper(vector<int>& arr, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int max_num = arr[left];
        int index = left;
        for (int i=left+1; i<=right; i++) {
            if (arr[i] > max_num) {
                max_num = arr[i];
                index = i;
            }
        }
        TreeNode* newnode = new TreeNode(max_num);
        newnode->left = helper(arr, left, index - 1);
        newnode->right = helper(arr, index + 1, right);
        return newnode;
    }

};