#ifndef VTECH_DATA_STRUCTURES_SINGLYLINKEDLIST_TPP
#define VTECH_DATA_STRUCTURES_SINGLYLINKEDLIST_TPP

#include "singlylinkedlist.h"

template<typename data_type>
SinglyLinkedList<data_type>::SinglyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

template<typename data_type>
SinglyLinkedList<data_type>::~SinglyLinkedList() {
    clear();
}

template<typename data_type>
bool SinglyLinkedList<data_type>::addFirst(data_type data) {
    if (length == std::numeric_limits<std::size_t>::max()) {
        return false;
    }

    auto * addedNode = new Node<data_type>{data};

    if (length == 0) {
        addedNode->next = nullptr;
        tail = addedNode;
    } else {
        addedNode->next = head;
    }
    head = addedNode;

    ++length;
    return true;
}

template<typename data_type>
bool SinglyLinkedList<data_type>::addLast(data_type data) {
    if (length == std::numeric_limits<std::size_t>::max()) {
        return false;
    }

    auto * addedNode = new Node<data_type>{data, nullptr};

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
bool SinglyLinkedList<data_type>::addMiddle(data_type data) {
    return add(data, length / 2);
}

template<typename data_type>
bool SinglyLinkedList<data_type>::add(data_type data, std::size_t index) {
    if (index == 0) {
        return addFirst(data);
    }
    if (index + 1 >= length) {
        return addLast(data);
    }
    if (length == std::numeric_limits<std::size_t>::max()) {
        return false;
    }

    Node<data_type> * currentNode = head;
    for (std::size_t i = index - 1; i --> 0;) {
        currentNode = currentNode->next;
    }

    currentNode->next = new Node<data_type>{data, currentNode->next};

    ++length;
    return true;
}

template<typename data_type>
bool SinglyLinkedList<data_type>::removeFirst() {
    if (isEmpty()) {
        return false;
    }

    Node<data_type> * nextNode = head->next;

    delete head;
    head = nextNode;
    if (head == nullptr) {
        tail = nullptr;
    }

    --length;
    return true;
}

template<typename data_type>
bool SinglyLinkedList<data_type>::removeLast() {
    if (length == 1) {
        removeFirst();
        return false;
    }
    if (isEmpty()) {
        return false;
    }

    Node<data_type> * currentNode = head;
    for (std::size_t i = length - 2; i --> 0;) {
        currentNode = currentNode->next;
    }

    currentNode->next = nullptr;
    delete tail;
    tail = currentNode;

    --length;
    return true;
}

template<typename data_type>
bool SinglyLinkedList<data_type>::removeMiddle() {
    return remove(length / 2);
}

template<typename data_type>
bool SinglyLinkedList<data_type>::remove(std::size_t index) {
    if (index == 0) {
        return removeFirst();
    }
    if (index + 1 >= length) {
        return removeLast();
    }

    Node<data_type> * currentNode = head;
    while (index --> 1) {
        currentNode = currentNode->next;
    }

    Node<data_type> * childNode = currentNode->next;

    currentNode->next = childNode->next;
    delete childNode;

    --length;
    return true;
}

template<typename data_type>
void SinglyLinkedList<data_type>::clear() {
    Node<data_type> * currentNode = head;
    while (currentNode != nullptr) {
        Node<data_type> * childNode = currentNode->next;

        delete currentNode;
        currentNode = childNode;
    }

    head = nullptr;
    tail = nullptr;
    length = 0;
}

template<typename data_type>
bool SinglyLinkedList<data_type>::reverse() {
    if (length <= 1) {
        return false;
    }

    tail = head;

    Node<data_type> * currentNode = head->next;
    do {
        Node<data_type> * childNode = currentNode->next;
        tail->next = childNode;

        currentNode->next = head;
        head = currentNode;

        currentNode = childNode;
    } while (currentNode != nullptr);

    return true;
}

template<typename data_type>
data_type * SinglyLinkedList<data_type>::getFirst() {
    if (head == nullptr) {
        return nullptr;
    }
    return &head->data;
}

template<typename data_type>
const data_type * SinglyLinkedList<data_type>::getFirst() const {
    return const_cast<SinglyLinkedList *>(this)->getFirst();
}

template<typename data_type>
data_type * SinglyLinkedList<data_type>::getLast() {
    if (tail == nullptr) {
        return nullptr;
    }
    return &tail->data;
}

template<typename data_type>
const data_type * SinglyLinkedList<data_type>::getLast() const {
    return const_cast<SinglyLinkedList *>(this)->getLast();
}

template<typename data_type>
data_type * SinglyLinkedList<data_type>::getMiddle() {
    return get(length / 2);
}

template<typename data_type>
const data_type * SinglyLinkedList<data_type>::getMiddle() const {
    return const_cast<SinglyLinkedList *>(this)->getMiddle();
}

template<typename data_type>
data_type * SinglyLinkedList<data_type>::get(std::size_t index) {
    if (index >= length) {
        return nullptr;
    }
    Node<data_type> * currentNode = head;
    for (std::size_t i = index; i --> 0;) {
        currentNode = currentNode->next;
    }

    return &currentNode->data;
}


template<typename data_type>
const data_type * SinglyLinkedList<data_type>::get(std::size_t index) const {
    return const_cast<SinglyLinkedList *>(this)->get(index);
}

template<typename data_type>
std::size_t SinglyLinkedList<data_type>::getLength() const {
    return length;
}

template<typename data_type>
bool SinglyLinkedList<data_type>::isEmpty() const {
    return length == 0;
}

#endif //VTECH_DATA_STRUCTURES_SINGLYLINKEDLIST_TPP
