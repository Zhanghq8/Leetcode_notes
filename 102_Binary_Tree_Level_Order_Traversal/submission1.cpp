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
        if (!root) {
            return {};
        }
        vector<vector<int>> result;
        queue<TreeNode*> sameLevelQueue;
        sameLevelQueue.push(root);
        while (!sameLevelQueue.empty()) {
            vector<int> elements;
            int length = sameLevelQueue.size();
            while (length) {
                TreeNode* front = sameLevelQueue.front();
                sameLevelQueue.pop();
                if (front->left) {
                    sameLevelQueue.push(front->left);    
                }
                if (front->right) {
                    sameLevelQueue.push(front->right);    
                }
                elements.push_back(front->val);
                length--;
            }
            result.emplace_back(elements);
        }
        return result;
    }
};

