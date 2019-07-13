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
    int kthSmallest(TreeNode* root, int k) {
        int result;
        stack<TreeNode*> S;
        TreeNode* current = root;
        int count = 1;
        while(current || !S.empty())
        {
            while (current)
            {
                S.push(current);
                current = current->left;
            }
            current = S.top();
            if (count == k)
            {
                result =  current->val;
            }
            S.pop();
            current = current->right;
            count++;
        }
        return result;
    }
};

