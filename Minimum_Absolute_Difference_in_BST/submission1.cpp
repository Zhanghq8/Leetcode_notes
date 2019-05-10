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
    int getMinimumDifference(TreeNode* root) {
        vector<int> ele = element(root);
        if (ele.size()<2) {
            return 0;
        }
        int mindiff = INT_MAX;
        int currentelement;
        for (int i=0; i<ele.size()-1; i++) {
            for (int j=i+1; j<ele.size(); j++) {
                currentelement = ele[i];
                if (abs(currentelement-ele[j])<mindiff) {
                    mindiff = abs(currentelement-ele[j]);
                }  
            }
        }
        return mindiff;
    }
    vector<int> element(TreeNode* root) {
        vector<int> element;
        if (root == NULL) {
            return element;
        }
        queue<TreeNode*> address;
        address.push(root);
        element.push_back(root->val);
        while (!address.empty()) {
            TreeNode* current = address.front();
            if (current->left != NULL) {
                address.push(current->left);
                element.push_back(current->left->val);
            }
            if (current->right != NULL) {
                address.push(current->right);
                element.push_back(current->right->val);
            }
            address.pop();
        }
        return element;
    }
};