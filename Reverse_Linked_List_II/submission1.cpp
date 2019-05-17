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
        ListNode* dummyhead = new ListNode(0);
        ListNode* previous = dummyhead;
        dummyhead->next = head;
        ListNode* current;
        for (int i=0; i<m-1; i++) {
            previous = previous->next;
        }
        current = previous->next;
        for (int i=0; i<n-m; i++) {
            ListNode* forward = current->next; 
            ListNode* temp = previous->next;
            previous->next = forward;
            current->next = forward->next;
            forward->next = temp;          
        }
        return dummyhead->next;
    }
};

