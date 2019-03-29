#include <iostream>
#include <string>
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

        if (head == NULL || head->next == NULL) {
            return false;
        }
        else {
            ListNode* currentnode = head;
            ListNode* nextnode = head->next;
            while (currentnode != nextnode) {
                if (nextnode == NULL || nextnode->next == NULL) {
                    return false;
                }
                else {
                    currentnode = currentnode->next;
                    nextnode = nextnode->next->next;
                }
            }
        }
        return true;
    }
};

