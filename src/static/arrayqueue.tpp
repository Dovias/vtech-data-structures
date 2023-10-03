#ifndef VTECH_DATA_STRUCTURES_ARRAYQUEUE_TPP
#define VTECH_DATA_STRUCTURES_ARRAYQUEUE_TPP

#include "arrayqueue.h"
#include "arraystack.h"

template<typename data_type>
ArrayQueue<data_type>::ArrayQueue(std::size_t capacity) : capacity(capacity), front(new data_type[capacity]), length(0) {}

template<typename data_type>
ArrayQueue<data_type>::~ArrayQueue() {
    delete[] front;
}

template<typename data_type>
bool ArrayQueue<data_type>::enqueue(data_type data) {
    if (isFull()) {
        return false;
    }
    front[length] = data;

    ++length;
    return true;
}

template<typename data_type>
bool ArrayQueue<data_type>::dequeue() {
    if (isEmpty()) {
        return false;
    }
    for (std::size_t i = 0, j = length - 1; i < j; ++i) {
        front[i] = front[i+1];
    }

    --length;
    return true;
}

template<typename data_type>
void ArrayQueue<data_type>::clear() {
    length = 0;
}

template<typename data_type>
data_type * ArrayQueue<data_type>::getFront() {
    if (isEmpty()) {
        return nullptr;
    }
    return front;
}

template<typename data_type>
const data_type * ArrayQueue<data_type>::getFront() const {
    return const_cast<ArrayQueue *>(this)->getFront();
}


template<typename data_type>
data_type * ArrayQueue<data_type>::getBack() {
    if (isEmpty()) {
        return nullptr;
    }
    return &front[length - 1];
}

template<typename data_type>
const data_type * ArrayQueue<data_type>::getBack() const {
    return const_cast<ArrayQueue *>(this)->getFront();
}

template<typename data_type>
std::size_t ArrayQueue<data_type>::getLength() const {
    return length;
}

template<typename data_type>
std::size_t ArrayQueue<data_type>::getCapacity() const {
    return capacity;
}

template<typename data_type>
bool ArrayQueue<data_type>::isEmpty() const {
    return length == 0;
}

template<typename data_type>
bool ArrayQueue<data_type>::isFull() const {
    return length == capacity;
}


#endif //VTECH_DATA_STRUCTURES_ARRAYQUEUE_TPP
