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
        if (head == NULL) {
            return NULL;
        }
        headresult = head;
        reverse(head);
        return headresult;
    }
private:
    void reverse(ListNode* temp) {
        if (temp->next == NULL) {
            headresult = temp;
            return;
        }
        reverse(temp->next);
        cout << temp << endl;
        // ListNode* current = temp->next;
        // current->next = temp; 
        // temp->next = NULL;
        ListNode* current = temp;
        current->next->next = current;
        current->next = NULL;  
    }
    ListNode* headresult;
};

