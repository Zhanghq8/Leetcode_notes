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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* oddindex = head;
        ListNode* evenindex = head->next;
        ListNode* even = head->next;
        while (oddindex->next != NULL && evenindex->next != NULL) {
            oddindex->next = evenindex->next;
            oddindex = oddindex->next;
            evenindex->next = oddindex->next;
            evenindex = evenindex->next;
        }
        oddindex->next = even;
        return head;
    }
};