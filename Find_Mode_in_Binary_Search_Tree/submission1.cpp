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
    vector<int> findMode(TreeNode* root) {
        element_inorder(root);
        return result;
    }
private:
    vector<int> result;
    int element = 0;
    int max_count = 0;
    int count = 0;
    void element_inorder(TreeNode* root) {
        stack<TreeNode*> S;
        TreeNode* current = root;
        while (!S.empty() || current) {
            while(current) {
                S.push(current);
                current = current->left;
            }
            current = S.top();
            add_modes(current->val);
            S.pop();
            current = current->right;
        }
    }
    void add_modes(int value) {
        if (count > 0 && value == element) {
            count++;
        }
        else {
            element = value;
            count = 1;
        }
        if (count == max_count) {
            result.push_back(value);
        }
        if (count > max_count) {
            max_count = count;
            result.clear();
            result.push_back(value);
        }
    }
};

