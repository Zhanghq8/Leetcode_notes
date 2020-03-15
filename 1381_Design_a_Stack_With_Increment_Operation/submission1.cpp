#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class CustomStack {
public:
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if (data.size() < size) {
            data.push(x);
        }
    }
    
    int pop() {
        if (data.empty()) {
            return -1;
        }
        int top = data.top();
        data.pop();
        return top;
    }
    
    void increment(int k, int val) {
        stack<int> temp;
        while (!data.empty()) {
            int top = data.top();
            data.pop();
            temp.push(top);
        }
        while (!temp.empty()) {
            int top = temp.top();
            temp.pop();
            if (k > 0) {
                data.push(top + val);
            } else {
                data.push(top);
            }
            k--;
        }
    }
private:
    stack<int> data;
    int size;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */