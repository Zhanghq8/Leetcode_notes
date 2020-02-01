#include <iostream>
#include <string>

using namespace std;


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        unordered_map<Node*, Node*> data;
        Node* cur = head->next;
        Node* copy = new Node(head->val);
        Node* copyCur = copy;
        data[head] = copy;
        while (cur) {
            Node* newNode = new Node(cur->val);
            copyCur->next = newNode;
            data[cur] = newNode;
            cur = cur->next;
            copyCur = copyCur->next;
        }
        cur = head;
        copyCur = copy;
        while (cur) {
            copyCur->random = data[cur->random];
            cur = cur->next;
            copyCur = copyCur->next;
        }
        return copy;
    }
};