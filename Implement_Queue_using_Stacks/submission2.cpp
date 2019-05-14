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
        temp.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = peek();
        queue_stack.pop();
        return top;
        
    }
    
    /** Get the front element. */
    int peek() {
        if (queue_stack.empty()) {
            while(temp.size() >= 1) {
                int top = temp.top();
                queue_stack.push(top);
                temp.pop();
            }
        }
        return queue_stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (temp.empty() && queue_stack.empty());
    }
    
private:
    stack<int> temp;
    stack<int> queue_stack;
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
