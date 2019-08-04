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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        else {
            ListNode* currentnode = head;
            ListNode* nextnode = head;
            int cnt = 1;
            while (currentnode != nextnode || cnt == 1) {
                if (nextnode->next == NULL || nextnode->next->next == NULL) {
                    return NULL;
                }
                else {
                    currentnode = currentnode->next;
                    nextnode = nextnode->next->next;
                }
                cnt++;
            }
            currentnode = head;
            while (currentnode != nextnode) {
                currentnode = currentnode->next;
                nextnode = nextnode->next;
            }
            return currentnode;
        }
    }
};

