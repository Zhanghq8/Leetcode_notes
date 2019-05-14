#include <iostream>
#include <string>
#include <queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        stack_queue.push(x);
        for (int i=1; i<stack_queue.size(); i++) {
            stack_queue.push(stack_queue.front());
            stack_queue.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = stack_queue.front();
        stack_queue.pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return stack_queue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return stack_queue.empty();
    }
private:
    queue<int> stack_queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() 
{
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    int top = obj->top();
    int pop = obj->pop();
    bool empty = obj->empty();
    cout << "top = " << top << ". " << endl;
    cout << "pop = " << pop << ". " << endl;
    cout << "empty = " << empty << ". " << endl;
    return 1;
}
