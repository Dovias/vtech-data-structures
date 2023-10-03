#ifndef VTECH_DATA_STRUCTURES_DOUBLELINKEDLIST_TPP
#define VTECH_DATA_STRUCTURES_DOUBLELINKEDLIST_TPP

#include "doublelinkedlist.h"

#include <limits>

template<typename data_type>
DoubleLinkedList<data_type>::DoubleLinkedList() : head(nullptr), tail(nullptr), length(0) {}

template<typename data_type>
DoubleLinkedList<data_type>::~DoubleLinkedList() {
    clear();
}

template<typename data_type>
bool DoubleLinkedList<data_type>::addFirst(data_type data) {
    if (length == std::numeric_limits<std::size_t>::max()) {
        return false;
    }

    auto * addedNode = new BidirectionalNode<data_type>{data, nullptr};

    if (length == 0) {
        addedNode->next = nullptr;
        tail = addedNode;
    } else {
        head->previous = addedNode;

        addedNode->next = head;
    }
    head = addedNode;

    ++length;
    return true;
}

template<typename data_type>
bool DoubleLinkedList<data_type>::addLast(data_type data) {
    if (length == std::numeric_limits<std::size_t>::max()) {
        return false;
    }

    auto * addedNode = new BidirectionalNode<data_type>{data, tail, nullptr};

    if (length == 0) {
        head = addedNode;
    } else {
        tail->next = addedNode;
    }
    tail = addedNode;

    ++length;
    return true;
}

template<typename data_type>
bool DoubleLinkedList<data_type>::addMiddle(data_type data) {
    return add(data, length / 2);
}

template<typename data_type>
bool DoubleLinkedList<data_type>::add(data_type data, std::size_t index) {
    if (index == 0) {
        return addFirst(data);
    }
    if (index + 1 >= length) {
        return addLast(data);
    }
    if (length == std::numeric_limits<std::size_t>::max()) {
        return false;
    }

    std::size_t distance = length - index - 1;
    BidirectionalNode<data_type> * currentNode;
    if (distance > index) {
        currentNode = head;
        while (index --> 0) {
            currentNode = currentNode->next;
        }
    } else {
        currentNode = tail;
        while (distance --> 0) {
            currentNode = currentNode->previous;
        }
    }

    BidirectionalNode<data_type> * parentNode = currentNode->previous;
    auto * insertedNode = new BidirectionalNode<data_type>{data, parentNode, currentNode};

    parentNode->next = insertedNode;
    currentNode->previous = insertedNode;

    ++length;
    return true;
}

template<typename data_type>
bool DoubleLinkedList<data_type>::removeFirst() {
    if (isEmpty()) {
        return false;
    }

    BidirectionalNode<data_type> * childNode = head->next;
    if (childNode != nullptr) {
        childNode->previous = nullptr;
    } else {
        tail = nullptr;
    }

    delete head;
    head = childNode;

    --length;
    return true;
}

template<typename data_type>
bool DoubleLinkedList<data_type>::removeLast() {
    if (length == 1) {
        removeFirst();
        return false;
    }
    if (isEmpty()) {
        return false;
    }

    BidirectionalNode<data_type> * parentNode = tail->previous;
    parentNode->next = nullptr;

    delete tail;
    tail = parentNode;

    --length;
    return true;
}

template<typename data_type>
bool DoubleLinkedList<data_type>::removeMiddle() {
    return remove(length / 2);
}

template<typename data_type>
bool DoubleLinkedList<data_type>::remove(std::size_t index) {
    if (index == 0) {
        return removeFirst();
    }
    if (index + 1 >= length) {
        return removeLast();
    }

    BidirectionalNode<data_type> * currentNode = head;
    std::size_t distance = length - index - 1;
    if (distance > index) {
        while (index --> 0) {
            currentNode = currentNode->next;
        }
    } else {
        currentNode = tail;
        while (distance --> 0) {
            currentNode = currentNode->previous;
        }
    }

    BidirectionalNode<data_type> * parentNode = currentNode->previous;
    BidirectionalNode<data_type> * childNode = currentNode->next;

    parentNode->next = childNode;
    childNode->previous = parentNode;

    delete currentNode;

    --length;
    return true;
}


// TODO: Prepare for boolean return type
template<typename data_type>
void DoubleLinkedList<data_type>::clear() {
    if (isEmpty()) {
        return;
    }

    BidirectionalNode<data_type> * currentNode = head;
    do {
        BidirectionalNode<data_type> * childNode = currentNode->next;

        delete currentNode;

        currentNode = childNode;
    } while (currentNode != nullptr);

    head = nullptr;
    tail = nullptr;
    length = 0;
}

template<typename data_type>
bool DoubleLinkedList<data_type>::reverse() {
    if (length <= 1) {
        return false;
    }

    BidirectionalNode<data_type> * currentNode = head;
    do {
        BidirectionalNode<data_type> * childNode = currentNode->next;

        currentNode->next = currentNode->previous;
        currentNode->previous = childNode;

        currentNode = childNode;
    } while (currentNode != nullptr);

    currentNode = tail;
    tail = head;
    head = currentNode;

    return true;
}

template<typename data_type>
data_type * DoubleLinkedList<data_type>::getFirst() {
    if (head == nullptr) {
        return nullptr;
    }
    return &head->data;
}

template<typename data_type>
const data_type * DoubleLinkedList<data_type>::getFirst() const {
    return const_cast<DoubleLinkedList *>(this)->getFirst();
}

template<typename data_type>
data_type * DoubleLinkedList<data_type>::getLast() {
    if (tail == nullptr) {
        return nullptr;
    }
    return &tail->data;
}

template<typename data_type>
const data_type * DoubleLinkedList<data_type>::getLast() const {
    return const_cast<DoubleLinkedList *>(this)->getLast();
}

template<typename data_type>
data_type * DoubleLinkedList<data_type>::getMiddle() {
    return get(length / 2);
}

template<typename data_type>
const data_type * DoubleLinkedList<data_type>::getMiddle() const {
    return const_cast<DoubleLinkedList *>(this)->getMiddle();
}

template<typename data_type>
data_type * DoubleLinkedList<data_type>::get(std::size_t index) {
    if (index >= length) {
        return nullptr;
    }

    BidirectionalNode<data_type> * currentNode;
    std::size_t distance = length - index - 1;
    if (distance > index) {
        currentNode = head;
        while (index --> 0) {
            currentNode = currentNode->next;
        }
    } else {
        currentNode = tail;
        while (distance --> 0) {
            currentNode = currentNode->previous;
        }
    }

    return &currentNode->data;
}

template<typename data_type>
const data_type * DoubleLinkedList<data_type>::get(std::size_t index) const {
    return const_cast<DoubleLinkedList *>(this)->get(index);
}

template<typename data_type>
std::size_t DoubleLinkedList<data_type>::getLength() const {
    return length;
}

template<typename data_type>
bool DoubleLinkedList<data_type>::isEmpty() const {
    return length == 0;
}

#endif //VTECH_DATA_STRUCTURES_DOUBLELINKEDLIST_TPP
