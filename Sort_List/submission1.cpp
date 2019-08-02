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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow = head;
        ListNode* pre = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l1;
        ListNode* l2;
        l2 = pre->next;
        pre->next = NULL;
        l1 = head;
        return merge(sortList(l1), sortList(l2));
    }
private:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            }
            else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        if (list1 == NULL) {
            cur->next = list2;
        }
        if (list2 == NULL) {
            cur->next = list1;
        }
        return dummyHead->next;
    }
};