#include <iostream>
#include <math.h>

// Hash table

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        set<ListNode*> S;
        ListNode* cur = headA;
        while (cur != NULL) {
            S.insert(cur);
            cur = cur->next;
        }
        cur = headB;
        while (cur != NULL) {
            if (S.find(cur) != S.end()) {
                return cur;
            }
            cur = cur->next;
        }
        return NULL;
    }
};