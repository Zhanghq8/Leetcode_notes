#include <iostream>
#include <string>

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }
        int length = 1;
        ListNode* temp = head;
        ListNode* pre_temp = NULL;
        ListNode* result;
        while (temp->next != NULL) {
            length++;
            temp = temp->next;
        }

        int new_k = k%length;
        if (length == 1 || k == 0 || new_k == 0) {
            return head;
        }
        ListNode* current = head;
        ListNode* previous = NULL;
        int gap = length -new_k;
        while (gap > 0) {
            previous = current;
            current = current->next;
            gap--;
        }
        result = current;
        temp->next = head;
        previous->next = NULL;
        return result;
    }
};
