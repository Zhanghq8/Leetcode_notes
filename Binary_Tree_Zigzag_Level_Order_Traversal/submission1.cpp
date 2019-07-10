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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root)
        {
            return result;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        int level = 0;
        while (!Q.empty())
        {
            int length = Q.size() - 1;
            level++;
            vector<int> elesamelevel;
            while (length >= 0)
            {   
                TreeNode* current = Q.front();
                if (current->left)
                {
                    Q.push(current->left);
                }
                if (current->right)
                {
                    Q.push(current->right);
                }
                elesamelevel.push_back(current->val);
                Q.pop();
                length--;
            }
            if (!(level % 2))
            {
                reverse(elesamelevel.begin(), elesamelevel.end());
            }
            result.push_back(elesamelevel);
        }
        return result;
    }
};

