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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* m_node = dummyhead;
        for (int i=0; i<m-1; i++) {
            m_node = m_node->next;
        }
        ListNode* pre = m_node;
        ListNode* cur = m_node->next;
        for (int i =m; i<n; i++) {
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummyhead->next;
    }
};
