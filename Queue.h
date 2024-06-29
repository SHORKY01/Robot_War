//Queue.h

#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept> // for overflow_error, underflow_error

const int MAX_SIZE = 100; // or any appropriate max size

template <typename T>
class Queue {
private:
    T elements[MAX_SIZE];
    int frontIndex;
    int rearIndex;

public:
    Queue();
    void enqueue(const T& item);
    T dequeue();
    T front() const;
    bool isEmpty() const;
    int size() const;
};

#endif // QUEUE_H
