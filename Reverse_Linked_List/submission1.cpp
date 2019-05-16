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
    ListNode* reverseList(ListNode* head) {
        ListNode *current, *previous, *forward;
        current = head;
        previous = NULL;
        while (current != NULL) {
            forward = current->next;
            current->next = previous;
            previous = current;
            current = forward;
        }
        head = previous;
        return head;
    }
};

