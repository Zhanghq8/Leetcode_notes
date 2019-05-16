#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int num = count(head);
        if (index<0 || index>num-1) {
            return -1;
        }
        ListNode* current = head;
        for (int i=0; i<index; i++) {
            current = current->next;
        }
        return current->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* newnode = new ListNode();
        newnode->val = val;
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
            return;
        }
        newnode->next = head;
        head = newnode;        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* newnode = new ListNode();
        newnode->val = val;
        newnode->next = NULL;
        ListNode* current = head;
        if (head == NULL) {
            head = newnode;
        }
        else {
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newnode;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        int num = count(head);
        if (index<=num) {
            if (index == 0 || index < 0) {
                addAtHead(val);
                return;
            }
            else if (index == num) {
                addAtTail(val);
                return;
            }
            ListNode* newnode = new ListNode();
            newnode->val = val;
            newnode->next = NULL;
            ListNode* previous = head;
            for (int i=0; i<index-1; i++) {
                previous = previous->next;
            }
            ListNode* current = previous->next;
            previous->next = newnode;
            newnode->next = current;
        }        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int num = count(head);
        if (index>=0 && index<=num-1) {
            ListNode* previous = head;
            if (index == 0) {
                head = head->next;
                return;
            }
            for (int i=0; i<index-1; i++) {
                previous = previous->next;
            }
            ListNode* current = previous->next;
            previous->next = current->next;
        }
    }
private:
    struct ListNode
    {
        int val;
        ListNode* next;
    };
    ListNode* head;
    int count(ListNode* head) {
        if (head == NULL) {
            return 0;
        }
        int count = 0;
        ListNode* current = head;
        while (current != NULL) {
            current = current->next;
            count += 1;
        }
        return count;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

