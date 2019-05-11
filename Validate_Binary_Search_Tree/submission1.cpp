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
    bool isValidBST(TreeNode* root) {
        vector<int> element = element_inorder(root);
        if (element.size() == 0) {
            return true;
        }
        else if (element.size() == 1) {
            return true;
        }
        int index1 = 0;
        int index2 = 1;
        bool result;
        while (index1<element.size()-1) {
            if (element[index1] < element[index2]) {
                result = true;
                
            }
            else {
                return false;
            }
            index1++;
            index2++;   
        }
        return result;
    }
private:
    vector<int> element_inorder(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        stack<TreeNode*> S;
        TreeNode* current = root;
        while (current!= NULL || !S.empty()) {
            while (current != NULL) {
                S.push(current);
                current = current->left;
            }
            current = S.top();
            S.pop();
            result.push_back(current->val);
            current = current->right;
        }
        return result;
    }
};
