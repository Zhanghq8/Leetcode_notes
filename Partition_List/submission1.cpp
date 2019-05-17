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
        ListNode* dummyhead = new ListNode(0);
        ListNode* previous = dummyhead;
        dummyhead->next = head;
        ListNode* current = head;
        while (previous->next && previous->next->val < x) {
            previous = previous->next;
        }
        current = previous;
        while (current->next) {
           if (current->next->val < x) {
               ListNode* forward = current->next;
               current->next = forward->next;
               forward->next = previous->next;
               previous->next = forward;
               previous = previous->next;
           }
           else {
               current = current->next;
           }            
       }
        return dummyhead->next;
    }
};

