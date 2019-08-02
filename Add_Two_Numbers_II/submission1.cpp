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
        stack<int> S1;
        stack<int> S2;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while (cur1 != NULL || cur2 != NULL) {
            if (cur1 != NULL) {
                S1.push(cur1->val);
                cur1 = cur1->next;
            }
            if (cur2 != NULL) {
                S2.push(cur2->val);
                cur2 = cur2->next;
            }
        }
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        int carry = 0;
        while (S1.empty() != true || S2.empty() != true || carry != 0) {
            int sum;
            if (S1.empty() != true && S2.empty()!= true) {
                sum = S1.top() + S2.top() + carry;
                S1.pop();
                S2.pop();
            }
            else if (S1.empty() != true) {
                sum = S1.top() + carry;
                S1.pop();
            }
            else if (S2.empty() != true) {
                sum = S2.top() + carry;
                S2.pop();
            }
            else {
                sum = carry;
            }
            carry = sum / 10;
            ListNode* node = new ListNode(sum%10);
            ListNode* next = cur->next;
            cur->next = node;
            node->next = next;
        }
        return dummyHead->next;
    }
};