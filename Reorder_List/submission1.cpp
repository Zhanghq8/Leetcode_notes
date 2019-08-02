#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Stack

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
    void reorderList(ListNode* head) {
        ListNode* cur = head;
        stack<ListNode*> node;
        int num = 0;
        while (cur != NULL) {
            num++;
            node.push(cur);
            cur = cur->next;
        }
        int stop_flag;
        if (num % 2 == 0) {
            stop_flag = num/2;
        }
        else {
            stop_flag = num/2 + 1;
        }
        ListNode* temp = head;
        int cnt = 1;
        while (temp != NULL) {
            ListNode* back = node.top();
            // cout << cnt << " " << temp << " " << back << endl;
            if (temp == back->next) {
                break;
            }
            back->next = temp->next;
            temp->next = back;
            node.pop();
            cnt++;
            if (cnt > stop_flag) {
                back->next = NULL;
            }
            temp = back->next;
        }
    }
};