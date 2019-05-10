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
        if (root == NULL) {
            return 0;
        }
        Inorder(root);
        int index1 = 0;
        int index2 = 1;
        int mindiff = INT_MAX;
        while (index1<element.size()-1) {
            if (mindiff > abs(element[index1]-element[index2])) {
                mindiff = abs(element[index1]-element[index2]);
            }
            index1++;
            index2++;
        }
        return mindiff;
        
    }
private:
    vector<int> element;
    void Inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        Inorder(root->left);
        element.push_back(root->val);
        Inorder(root->right);
    }    
};