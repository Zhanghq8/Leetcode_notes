#include <iostream>
#include <string>
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        temp1.push(x);
        int length = temp1.size();
        while (!queue_stack.empty()) {
            queue_stack.pop();
            length--;
        }
        stack<int> temp2(temp1);
        for (int i=0; i<temp1.size(); i++) {
            int top = temp2.top();
            queue_stack.push(top);
            temp2.pop();
        }    
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int front = queue_stack.top();
        queue_stack.pop();
        stack<int> temp3(queue_stack);
        while (!temp1.empty()) {
            temp1.pop();
        }
        for (int i=0; i<temp3.size(); i++) {
            int top = temp3.top();
            temp1.push(top);
            temp3.pop();
        }
        return front;
    }
    
    /** Get the front element. */
    int peek() {
        return queue_stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return queue_stack.empty();
    }
private:
    stack<int> queue_stack;
    stack<int> temp1;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() 
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    int peek = obj->peek();
    int pop = obj->pop();
    bool empty = obj->empty();
    cout << "peek = " << peek << ". " << endl;
    cout << "pop = " << pop << ". " << endl;
    cout << "empty = " << empty << ". " << endl;
    return 1;
}
