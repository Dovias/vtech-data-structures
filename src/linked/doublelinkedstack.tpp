#ifndef VTECH_DATA_STRUCTURES_DOUBLELINKEDSTACK_TPP
#define VTECH_DATA_STRUCTURES_DOUBLELINKEDSTACK_TPP

#include "doublelinkedstack.h"

#include <limits>

template<typename data_type>
DoubleLinkedStack<data_type>::DoubleLinkedStack() = default;

template<typename data_type>
DoubleLinkedStack<data_type>::~DoubleLinkedStack() {
    clear();
}

template<typename data_type>
bool DoubleLinkedStack<data_type>::push(data_type data) {
    return list.addLast(data);
}

template<typename data_type>
bool DoubleLinkedStack<data_type>::pop() {
    return list.removeLast();
}

template<typename data_type>
void DoubleLinkedStack<data_type>::clear() {
    list.clear();
}

template<typename data_type>
data_type * DoubleLinkedStack<data_type>::getTop() {
    return list.getLast();
}

template<typename data_type>
const data_type * DoubleLinkedStack<data_type>::getTop() const {
    return const_cast<DoubleLinkedStack *>(this)->getTop();
}

template<typename data_type>
std::size_t DoubleLinkedStack<data_type>::getSize() const {
    return list.getLength();
}

template<typename data_type>
bool DoubleLinkedStack<data_type>::isEmpty() const {
    return list.isEmpty();
}

#endif //VTECH_DATA_STRUCTURES_DOUBLELINKEDSTACK_TPP
