// leetcode 641. Design Circular Deque

// Design your implementation of the circular double-ended queue (deque).

// Implement the MyCircularDeque class:

// MyCircularDeque(int k) Initializes the deque with a maximum size of k.
// boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
// boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
// boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
// boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
// int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
// int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
// boolean isEmpty() Returns true if the deque is empty, or false otherwise.
// boolean isFull() Returns true if the deque is full, or false otherwise.

#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:
    vector<int> dq;
    int size, capacity, front, back;
    MyCircularDeque(int k) {
        dq.resize(k, -1);
        front = 0;
        size = 0;
        back = k - 1;
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;
        front = (front - 1 + capacity) % capacity;
        dq[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;
        back = (back + 1) % capacity;
        dq[back] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;
        back = (back - 1 + capacity) % capacity;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;
        return dq[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;
        return dq[back];
    }

    bool isEmpty() {
        if (size == 0)
            return true;
        return false;
    }

    bool isFull() {
        if (size == capacity)
            return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */