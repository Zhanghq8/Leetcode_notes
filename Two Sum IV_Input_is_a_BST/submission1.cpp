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
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) {
            return false;
        }
        vector<int> result;
        stack<TreeNode*> S;
        TreeNode* current = root;
        while (current != NULL || !S.empty()) {
            while (current != NULL) {
                S.push(current);
                current = current->left;
            }
            current = S.top();
            S.pop();
            result.push_back(current->val);
            current = current->right;
        }
        int left = 0;
        int right = result.size() - 1;
        cout << right <<endl;
        while (left < right) {
            if (result[left] + result[right] == k) {
                return true;
            }
            else if (result[left] + result[right] > k) {
                right--;
            }
            else {
                left++;
            }
        }
        return false;
    }
};