#include <iostream>
#include <vector>

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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
             return false;
        }
        ListNode* slowPtr = head;
        ListNode* fastPtr = head->next;
        while (slowPtr != fastPtr) {
            if (!fastPtr || !fastPtr->next) {
              return false;
            }
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        return true;
    }
};
