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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller_head = new ListNode(0);
        ListNode* s_head = smaller_head;
        ListNode* greater_head = new ListNode(0);
        ListNode* g_head = greater_head;
        while (head) {
            if (head->val < x) {
                s_head->next = head;
                s_head = s_head->next;
                
            }
            else {
                g_head->next = head;
                g_head = g_head->next;
            }
            head = head->next;
        }
        g_head->next = NULL;
        s_head->next = greater_head->next;
        return smaller_head->next;
    }
};
