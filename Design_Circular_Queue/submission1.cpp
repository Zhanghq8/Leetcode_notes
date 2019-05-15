#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        head = 0;
        tail = 0;
        element = vector<int> (k, 0);
        size = k; 
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        ++tail;
        element[(tail-1)%size] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        ++head;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return element[head%size];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return element[(tail-1)%size];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if (tail == head) {
            return true;
        }
        return false;        
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if (tail - head == size) {
            return true;
        }
        return false;
    }
private:
    int head, tail, size;
    vector<int> element;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() 
{
    int k = 3;
    MyCircularQueue* obj = new MyCircularQueue(k);
    bool param_1 = obj->enQueue(2);
    bool param_2 = obj->deQueue();
    int param_3 = obj->Rear();
    int param_4 = obj->Front();
    bool param_5 = obj->deQueue();
    int param_6 = obj->Front();
    bool param_7 = obj->enQueue(3);
    int param_8 = obj->Front();
    bool param_9 = obj->isEmpty();
    bool param_10 = obj->isFull();

    cout << "Param1: " << param_1 << "." << endl;
    cout << "Param2: " << param_2 << "." << endl;
    cout << "Param3: " << param_3 << "." << endl;
    cout << "Param4: " << param_4 << "." << endl;
    cout << "Param5: " << param_5 << "." << endl;
    cout << "Param6: " << param_6 << "." << endl;
    cout << "Param7: " << param_7 << "." << endl;
    cout << "Param8: " << param_8 << "." << endl;
    cout << "Param9: " << param_9 << "." << endl;
    cout << "Param10: " << param_10 << "." << endl;
}