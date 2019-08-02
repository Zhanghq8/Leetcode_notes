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
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rightlist = slow->next;
        ListNode* cur = slow->next;
        ListNode* pre = NULL;
        ListNode* next;
        while (cur != NULL) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        cur = head;
        ListNode* cur_new = pre;
        while (cur_new != NULL) {
            if (cur->val == cur_new->val) {
                cur = cur->next;
                cur_new = cur_new->next;
            }
            else {
                return false;
            }
        }
        return true;
    }
};