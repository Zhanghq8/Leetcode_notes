#include <iostream>
#include <string>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        all_elementStack.push(x);
        if (min_elementStack.empty() || min_elementStack.top() >= x) {
            min_elementStack.push(x);
        }    
    }
    
    void pop() {
        if (min_elementStack.top() == all_elementStack.top()) {
            min_elementStack.pop();
        }
        all_elementStack.pop();
    }
    
    int top() {
        return all_elementStack.top();
    }
    
    int getMin() {
        return min_elementStack.top();
    }
private:
    stack<int> all_elementStack;
    stack<int> min_elementStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() 
{
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    int min1 = obj->getMin();
    obj->pop();
    int top1 = obj->top();  
    int min2 = obj->getMin();
    cout << "min1 = " << min1 << ". " << endl;
    cout << "top1 = " << top1 << ". " << endl;
    cout << "min2 = " << min2 << ". " << endl;
    return 1;
}

