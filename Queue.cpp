//Queue.cpp

#include "Queue.h"
#include "TBot.h"
#include "DerivedRobot.h"

// Implementation of Queue<T> methods

template <typename T>
Queue<T>::Queue() : frontIndex(-1), rearIndex(-1) {}

template <typename T>
void Queue<T>::enqueue(const T& item) {
    if (rearIndex == MAX_SIZE - 1) {
        throw std::overflow_error("Queue is full");
    }
    if (frontIndex == -1) {
        frontIndex = 0;
    }
    elements[++rearIndex] = item;
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    T item = elements[frontIndex++];
    if (frontIndex > rearIndex) {
        frontIndex = rearIndex = -1;
    }
    return item;
}

template <typename T>
T Queue<T>::front() const {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    return elements[frontIndex];
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return frontIndex == -1;
}

template <typename T>
int Queue<T>::size() const {
    if (isEmpty()) {
        return 0;
    }
    return rearIndex - frontIndex + 1;
}

// Explicit instantiation of the template classes
template class Queue<int>; // Replace with your desired types as needed
template class Queue<Robot*>;
template class Queue<SimpleBot*>; // Explicit instantiation for SimpleBot*
template class Queue<RoboCop*>; // Explicit instantiation for Robocop*
template class Queue<Terminator*>; // Explicit instantiation for Terminator*
template class Queue<TerminatorRoboCop*>; // Explicit instantiation for TerminatorRobocop*
template class Queue<BlueThunder*>; // Explicit instantiation for BlueThunder*
template class Queue<Madbot*>; // Explicit instantiation for MadBot*
template class Queue<RoboTank*>; // Explicit instantiation for RoboTank*
template class Queue<UltimateRobot*>; // Explicit instantiation for UltimateRobot*
