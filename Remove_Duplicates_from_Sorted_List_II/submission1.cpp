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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyhead = new ListNode(0);
        ListNode* previous = dummyhead;
        dummyhead->next = head;
        while (previous->next) {
            ListNode* current = previous->next;
            while (current->next && current->val == current->next->val) {
                current = current->next;
            }
            if (current != previous->next) {
                previous->next = current->next;
            }
            else {
                previous = previous->next;
            }
            
        }
        return dummyhead->next;
    }
};
