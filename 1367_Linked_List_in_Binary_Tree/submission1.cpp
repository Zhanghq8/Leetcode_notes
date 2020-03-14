#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) {
            return true;
        }
        if (!root) {
            return false;
        }
        if (head->val == root->val) {
            if (helper(head->next, root->left)) {
                return true;
            }
            if (helper(head->next, root->right)) {
                return true;
            }
        }
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
private:
    bool helper(ListNode* cur, TreeNode* newRoot) {
        if (!cur) {
            return true;
        }
        if (!newRoot) {
            return false;
        }
        if (cur->val != newRoot->val) {
            return false;
        }
        return helper(cur->next, newRoot->left) || helper(cur->next, newRoot->right); 
    }
};