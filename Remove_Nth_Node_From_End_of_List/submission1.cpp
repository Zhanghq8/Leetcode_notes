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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num = count(head);
        if (n>=0 && n<=num) {
            int index = num - n;
            if (index == 0) {
                head = head->next;
                return head;
            }
            ListNode* previous = head;
            for (int i=0; i<index-1; i++) {
                previous = previous->next;
            }
            ListNode* current = previous->next;
            previous->next = current->next;
        }
        return head;
    }
private:
    int count(ListNode* head) {
        int num = 0;
        if (head == NULL) {
            return num;
        }
        ListNode* current = head;
        while (current != NULL) {
            current = current->next;
            num += 1;
        }
        return num;
    }
};

