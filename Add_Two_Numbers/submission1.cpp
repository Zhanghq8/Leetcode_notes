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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* cur = dummyHead;
        int carry = 0;
        while (cur1 != NULL || cur2 != NULL) {
            int num1 = 0, num2 = 0;
            if (cur1 != NULL) {
                num1 = cur1->val;
            }
            if (cur2 != NULL) {
                num2 = cur2->val;
            }
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            ListNode* next = new ListNode(sum%10);
            cur->next = next;
            cur = cur->next;
            if (cur1 != NULL) {
                cur1 = cur1->next;
            }
            if (cur2 != NULL) {
                cur2 = cur2->next;
            }
        }
        if (carry > 0) {
            ListNode* last = new ListNode(carry);
            cur->next = last;
        }
        return dummyHead->next;
    }
};