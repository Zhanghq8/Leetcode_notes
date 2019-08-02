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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = head;
        while (cur != NULL) {
            ListNode* temp = cur->next;
            ListNode* cur_new = dummyHead;
            while (cur_new->next != NULL && cur_new->next->val < cur->val) {
                cur_new = cur_new->next;
            }
            cur->next = cur_new->next;
            cur_new->next = cur;
            cur = temp;          
        }
        return dummyHead->next;
    }
};
