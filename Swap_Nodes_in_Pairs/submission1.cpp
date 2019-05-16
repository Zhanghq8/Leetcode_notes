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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode *pre, *cur, *next;
        pre = dummyhead;
        cur = head;
        next = head->next;
        while (cur != NULL && next != NULL) {
            cur->next = next->next;
            next->next = cur;
            pre->next = next;
            pre = cur;
            cur = cur->next;
            if (cur != NULL) {
                next = cur->next;
            }
        }
        return dummyhead->next;
    }
};

