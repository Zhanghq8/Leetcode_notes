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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        if (l1 == NULL || l2 == NULL) {
            if (l1 == NULL) {
                return l2;
            }
            else {
                return l1;
            }
        }
        ListNode* node;
        if (l1->val < l2->val) {
            node = l1;
            node->next = mergeTwoLists(l1->next, l2);
        }
        else {
            node = l2;
            node->next = mergeTwoLists(l2->next, l1);            
        }
        return node;
    }
};

