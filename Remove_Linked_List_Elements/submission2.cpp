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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* current = head;
        while (current->next != NULL) {
            if (current->next->val == val) {
                current->next = current->next->next;
            }
            else {
                current = current->next;
            }
            
        }
        if (head->val == val) {
            head = head->next;
        }
        return head;
    }
};
