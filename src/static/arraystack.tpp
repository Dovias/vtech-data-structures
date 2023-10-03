#ifndef VTECH_DATA_STRUCTURES_ARRAYSTACK_TPP
#define VTECH_DATA_STRUCTURES_ARRAYSTACK_TPP

#include "arraystack.h"

template<typename data_type>
ArrayStack<data_type>::ArrayStack(std::size_t capacity) : top(new data_type[capacity]), capacity(capacity), size(0) {}

template<typename data_type>
ArrayStack<data_type>::~ArrayStack() {
    top -= size;
    delete[] top;
}

template<typename data_type>
bool ArrayStack<data_type>::push(data_type data) {
    if (isFull()) {
        return false;
    }

    *top = data;

    ++top;
    ++size;
    return true;
}

template<typename data_type>
bool ArrayStack<data_type>::pop() {
    if (isEmpty()) {
        return false;
    }

    --top;
    --size;
    return true;
}

template<typename data_type>
void ArrayStack<data_type>::clear() {
    top -= size;
    size = 0;
}

template<typename data_type>
data_type * ArrayStack<data_type>::getTop() {
    if (isEmpty()) {
        return nullptr;
    }
    return top - 1;
}

template<typename data_type>
const data_type * ArrayStack<data_type>::getTop() const {
    return const_cast<ArrayStack *>(this)->getTop();

}

template<typename data_type>
std::size_t ArrayStack<data_type>::getSize() const {
    return size;
}

template<typename data_type>
std::size_t ArrayStack<data_type>::getCapacity() const {
    return capacity;
}

template<typename data_type>
bool ArrayStack<data_type>::isEmpty() const {
    return size == 0;
}

template<typename data_type>
bool ArrayStack<data_type>::isFull() const {
    return size == capacity;
}
#endif //VTECH_DATA_STRUCTURES_ARRAYSTACK_TPP
