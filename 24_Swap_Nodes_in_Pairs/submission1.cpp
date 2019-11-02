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
        ListNode* dummyhead = new ListNode(-1);
        ListNode* pre = dummyhead;
        dummyhead->next = head;
        while (pre->next && pre->next->next) {
            ListNode* cur = pre->next;
            ListNode* next = cur->next;
            ListNode* temp = next->next;
            pre->next = next;
            next->next = cur;
            cur->next = temp;
            pre = cur;
        }
        return dummyhead->next;
    }
};
