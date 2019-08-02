#include <iostream>
#include <math.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack <ListNode*> S;
        ListNode* cur = head;
        while (cur != NULL) {
            S.push(cur);
            cur = cur->next;
        }
        cur = head;
        while (cur != NULL) {
            if (cur->val == S.top()->val) {
                cur = cur->next;
                S.pop();
            }
            else {
                return false;
            }
        }
        return true;
    }
};