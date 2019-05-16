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
        ListNode* dummy = new ListNode(val-1);
        dummy->next = head;
        ListNode* previous = dummy; 
        while (previous->next != NULL) {
            if (previous->next->val == val) {
                previous->next = previous->next->next;
            }
            else {
                previous = previous->next;
            }
        }
        return dummy->next;
    }
};

