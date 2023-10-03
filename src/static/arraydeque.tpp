#ifndef VTECH_DATA_STRUCTURES_ARRAYDEQUE_TPP
#define VTECH_DATA_STRUCTURES_ARRAYDEQUE_TPP

#include "arraydeque.h"

template<typename data_type>
ArrayDeque<data_type>::ArrayDeque(std::size_t capacity) : capacity(capacity), front(new data_type[capacity]), size(0) {}

template<typename data_type>
ArrayDeque<data_type>::~ArrayDeque() {
    delete[] front;
}

// Gali buti labiau suoptimizuotas functionalumas jei mes seksime pradzios ir pabaigos laisvas vietas
// po elementu pasalinimo, tada galetu but idejimas ir isemimas greitesnis (be ciklo) jeigu mes isnaikinom
// ar pridejom is pradzios ar pabaigos atitinkamai. Siuo atveju tas nera implementuota del suprantamumo.
// - PRADZIA -
template<typename data_type>
bool ArrayDeque<data_type>::pushFront(data_type data) {
    if (isFull()) {
        return false;
    }
    ++size;

    for (std::size_t i = size; i --> 1;) {
        front[i] = front[i-1];
    }
    front[0] = data;

    return true;
}

template<typename data_type>
bool ArrayDeque<data_type>::pushBack(data_type data) {
    if (isFull()) {
        return false;
    }
    front[size] = data;

    ++size;
    return true;
}

template<typename data_type>
bool ArrayDeque<data_type>::popFront() {
    if (isEmpty()) {
        return false;
    }
    for (std::size_t i = 0, j = size - 1; i < j; ++i) {
        front[i] = front[i+1];
    }

    --size;
    return true;
}

template<typename data_type>
bool ArrayDeque<data_type>::popBack() {
    if (isEmpty()) {
        return false;
    }

    --size;
    return true;
}
// - PABAIGA -

template<typename data_type>
void ArrayDeque<data_type>::clear() {
    size = 0;
}


template<typename data_type>
data_type * ArrayDeque<data_type>::getFront() {
    return front;
}

template<typename data_type>
const data_type * ArrayDeque<data_type>::getFront() const {
    return const_cast<ArrayDeque *>(this)->getFront();
}

template<typename data_type>
data_type * ArrayDeque<data_type>::getBack() {
    return &front[size - 1];
}

template<typename data_type>
const data_type * ArrayDeque<data_type>::getBack() const {
    return const_cast<ArrayDeque *>(this)->getBack();
}

template<typename data_type>
std::size_t ArrayDeque<data_type>::getSize() const {
    return size;
}

template<typename data_type>
std::size_t ArrayDeque<data_type>::getCapacity() const {
    return capacity;
}

template<typename data_type>
bool ArrayDeque<data_type>::isEmpty() const {
    return size == 0;
}

template<typename data_type>
bool ArrayDeque<data_type>::isFull() const {
    return size == capacity;
}

#endif //VTECH_DATA_STRUCTURES_ARRAYDEQUE_TPP
