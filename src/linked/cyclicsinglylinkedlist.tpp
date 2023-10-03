#ifndef VTECH_DATA_STRUCTURES_CYCLICSINGLYLINKEDLIST_TPP
#define VTECH_DATA_STRUCTURES_CYCLICSINGLYLINKEDLIST_TPP

#include "cyclicsinglylinkedlist.h"

template<typename data_type>
CyclicSinglyLinkedList<data_type>::CyclicSinglyLinkedList() : last(nullptr), length(0) {}

template<typename data_type>
CyclicSinglyLinkedList<data_type>::~CyclicSinglyLinkedList() {
    clear();
}

template<typename data_type>
bool CyclicSinglyLinkedList<data_type>::addFirst(data_type data) {
    if (length == std::numeric_limits<std::size_t>::max()) {
        return false;
    }

    auto * addedNode = new Node<data_type>{data};
    if (isEmpty()) {
        addedNode->next = addedNode;
        last = addedNode;
    } else {
        addedNode->next = last->next;
        last->next = addedNode;
    }

    ++length;
    return true;
}

template<typename data_type>
bool CyclicSinglyLinkedList<data_type>::addLast(data_type data) {
    bool result = addFirst(data);
    if (result) {
        last = last->next;
    }
    return result;
}

template<typename data_type>
bool CyclicSinglyLinkedList<data_type>::addMiddle(data_type data) {
    return add(data, length / 2);
}

template<typename data_type>
bool CyclicSinglyLinkedList<data_type>::add(data_type data, std::size_t index) {
    // Sumazina kieki kiek reiks persokti
    index %= length;

    if (index == 0) {
        return addFirst(data);
    }
    if (length == std::numeric_limits<std::size_t>::max()) {
        return false;
    }

    Node<data_type> * currentNode = last;
    while (index --> 0) {
        currentNode = currentNode->next;
    }

    currentNode->next = new Node<data_type>{data, currentNode->next};
    ++length;
    return true;
}

template<typename data_type>
bool CyclicSinglyLinkedList<data_type>::removeFirst() {
    if (isEmpty()) {
        return false;
    }

    Node<data_type> * firstNode = last->next;
    if (firstNode == last) {
        last = nullptr;
    } else {
        last->next = firstNode->next;
    }

    delete firstNode;

    --length;
    return true;
}

template<typename data_type>
bool CyclicSinglyLinkedList<data_type>::removeLast() {
    if (isEmpty()) {
        return false;
    }
    if (length == 1) {
        return removeFirst();
    }

    Node<data_type> * currentNode = last;
    for (std::size_t i = length - 1; i --> 0;) {
        currentNode = currentNode->next;
    }

    currentNode->next = last->next;

    delete last;

    last = currentNode;
    --length;
    return true;
}


template<typename data_type>
bool CyclicSinglyLinkedList<data_type>::removeMiddle() {
    return remove(length / 2);
}

template<typename data_type>
bool CyclicSinglyLinkedList<data_type>::remove(std::size_t index) {
    if (index + 1 == length) {
        return removeLast();
    }
    if (index == 0) {
        return removeFirst();
    }
    if (isEmpty() || index >= length) {
        return false;
    }

    Node<data_type> * currentNode = last;
    while (index --> 0) {
        currentNode = currentNode->next;
    }

    Node<data_type> * childNode = currentNode->next;
    currentNode->next = childNode->next;

    delete childNode;

    --length;
    return true;
}

template<typename data_type>
void CyclicSinglyLinkedList<data_type>::clear() {
    if (isEmpty()) {
        return;
    }

    Node<data_type> * currentNode = last;
    do {
        Node<data_type> * childNode = currentNode->next;

        delete currentNode;

        currentNode = childNode;
    } while (currentNode != last);

    last = nullptr;
    length = 0;
}

template<typename data_type>
bool CyclicSinglyLinkedList<data_type>::reverse() {
    if (length <= 1) {
        return false;
    }

    Node<data_type> * parentNode = last;
    Node<data_type> * childNode = parentNode->next;
    do {
        Node<data_type> * grandChildNode = childNode->next;

        childNode->next = parentNode;

        parentNode = childNode;
        childNode = grandChildNode;
    } while (parentNode != last);

    last = childNode;
    return true;
}

template<typename data_type>
data_type * CyclicSinglyLinkedList<data_type>::getFirst() {
    if (isEmpty()) {
        return nullptr;
    }
    return &last->next->data;
}

template<typename data_type>
const data_type * CyclicSinglyLinkedList<data_type>::getFirst() const {
    return const_cast<CyclicSinglyLinkedList *>(this)->getFirst();
}

template<typename data_type>
data_type * CyclicSinglyLinkedList<data_type>::getLast() {
    return &last->data;
}

template<typename data_type>
const data_type * CyclicSinglyLinkedList<data_type>::getLast() const {
    return const_cast<CyclicSinglyLinkedList *>(this)->getLast();
}

template<typename data_type>
data_type * CyclicSinglyLinkedList<data_type>::getMiddle() {
    return get(length / 2);
}

template<typename data_type>
const data_type * CyclicSinglyLinkedList<data_type>::getMiddle() const {
    return const_cast<CyclicSinglyLinkedList *>(this)->getMiddle();
}

template<typename data_type>
data_type * CyclicSinglyLinkedList<data_type>::get(std::size_t index) {
    if (isEmpty()) {
        return nullptr;
    }

    // Sumazina kieki kiek reiks persokti
    index %= length;

    Node<data_type> * currentNode = last;
    do {
        currentNode = currentNode->next;
    } while (index --> 0);

    return &currentNode->data;
}

template<typename data_type>
const data_type * CyclicSinglyLinkedList<data_type>::get(std::size_t index) const {
    return const_cast<CyclicSinglyLinkedList *>(this)->get(index);
}

template<typename data_type>
std::size_t CyclicSinglyLinkedList<data_type>::getLength() const {
    return length;
}
template<typename data_type>
bool CyclicSinglyLinkedList<data_type>::isEmpty() const {
    return length == 0;
}


#endif //VTECH_DATA_STRUCTURES_CYCLICSINGLYLINKEDLIST_TPP
