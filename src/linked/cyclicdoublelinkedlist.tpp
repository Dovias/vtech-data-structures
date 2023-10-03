#ifndef VTECH_DATA_STRUCTURES_CYCLICDOUBLELINKEDLIST_TPP
#define VTECH_DATA_STRUCTURES_CYCLICDOUBLELINKEDLIST_TPP

#include "cyclicdoublelinkedlist.h"

template<typename data_type>
CyclicDoubleLinkedList<data_type>::CyclicDoubleLinkedList() : last(nullptr), length(0) {}

template<typename data_type>
CyclicDoubleLinkedList<data_type>::~CyclicDoubleLinkedList() {
    clear();
}

template<typename data_type>
bool CyclicDoubleLinkedList<data_type>::addFirst(data_type data) {
    if (length == std::numeric_limits<std::size_t>::max()) {
        return false;
    }

    auto * addedNode = new BidirectionalNode<data_type>{data};
    if (isEmpty()) {
        addedNode->next = addedNode;
        addedNode->previous = addedNode;

        last = addedNode;
    } else {
        addedNode->next = last->next;
        addedNode->previous = last;

        last->next->previous = addedNode;
        last->next = addedNode;
    }

    ++length;
    return true;
}

template<typename data_type>
bool CyclicDoubleLinkedList<data_type>::addLast(data_type data) {
    bool result = addFirst(data);
    if (result) {
        last = last->next;
    }
    return result;
}

template<typename data_type>
bool CyclicDoubleLinkedList<data_type>::addMiddle(data_type data) {
    return add(data, length / 2);
}

template<typename data_type>
bool CyclicDoubleLinkedList<data_type>::add(data_type data, std::size_t index) {
    // Sumazina kieki kiek reiks persokti
    index %= length;

    if (index == 0) {
        return addFirst(data);
    }
    if (length == std::numeric_limits<std::size_t>::max()) {
        return false;
    }

    BidirectionalNode<data_type> * currentNode = last;
    std::size_t distance = length - index - 1;
    if (distance > index) {
        do {
            currentNode = currentNode->next;
        } while (index --> 0);
    } else {
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
bool CyclicDoubleLinkedList<data_type>::removeFirst() {
    if (isEmpty()) {
        return false;
    }

    BidirectionalNode<data_type> * firstNode = last->next;
    if (firstNode == last) {
        last = nullptr;
    } else {
        last->next = firstNode->next;
        last->next->previous = last;
    }

    delete firstNode;

    --length;
    return true;
}

template<typename data_type>
bool CyclicDoubleLinkedList<data_type>::removeLast() {
    if (isEmpty()) {
        return false;
    }
    if (length == 1) {
        return removeFirst();
    }

    BidirectionalNode<data_type> * parentNode = last->previous;
    parentNode->next = last->next;
    last->next->previous = parentNode;

    delete last;

    last = parentNode;
    --length;
    return true;
}

template<typename data_type>
bool CyclicDoubleLinkedList<data_type>::removeMiddle() {
    return remove(length / 2);
}

template<typename data_type>
bool CyclicDoubleLinkedList<data_type>::remove(std::size_t index) {
    if (index + 1 == length) {
        return removeLast();
    }
    if (index == 0) {
        return removeFirst();
    }
    if (isEmpty() || index >= length) {
        return false;
    }

    BidirectionalNode<data_type> * currentNode = last;
    std::size_t distance = length - index - 1;
    if (distance > index) {
        ++index;

        while (index --> 0) {
            currentNode = currentNode->next;
        }
    } else {
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

template<typename data_type>
void CyclicDoubleLinkedList<data_type>::clear() {
    if (isEmpty()) {
        return;
    }

    BidirectionalNode<data_type> * currentNode = last;
    do {
        BidirectionalNode<data_type> * childNode = currentNode->next;

        delete currentNode;

        currentNode = childNode;
    } while (currentNode != last);

    last = nullptr;
    length = 0;
}

template<typename data_type>
bool CyclicDoubleLinkedList<data_type>::reverse() {
    if (length <= 1) {
        return false;
    }

    BidirectionalNode<data_type> * currentNode = last;
    do {
        BidirectionalNode<data_type> * childNode = currentNode->next;

        currentNode->next = currentNode->previous;
        currentNode->previous = childNode;

        currentNode = childNode;
    } while (currentNode != last);

    last = currentNode->next;
    return true;
}

template<typename data_type>
data_type * CyclicDoubleLinkedList<data_type>::getFirst() {
    if (isEmpty()) {
        return nullptr;
    }
    return &last->next->data;
}

template<typename data_type>
const data_type * CyclicDoubleLinkedList<data_type>::getFirst() const {
    return const_cast<CyclicDoubleLinkedList *>(this)->getFirst();
}

template<typename data_type>
data_type * CyclicDoubleLinkedList<data_type>::getLast() {
    return &last->data;
}

template<typename data_type>
const data_type * CyclicDoubleLinkedList<data_type>::getLast() const {
    return const_cast<CyclicDoubleLinkedList *>(this)->getLast();
}

template<typename data_type>
data_type * CyclicDoubleLinkedList<data_type>::getMiddle() {
    return get(length / 2);
}

template<typename data_type>
const data_type * CyclicDoubleLinkedList<data_type>::getMiddle() const {
    return const_cast<CyclicDoubleLinkedList *>(this)->getMiddle();
}

template<typename data_type>
data_type * CyclicDoubleLinkedList<data_type>::get(std::size_t index) {
    if (isEmpty()) {
        return nullptr;
    }

    // Sumazina kieki kiek reiks persokti
    index %= length;

    BidirectionalNode<data_type> * currentNode = last;
    std::size_t distance = length - index - 1;
    if (distance > index) {
        do {
            currentNode = currentNode->next;
        } while (index --> 0);
    } else {
        while (distance --> 0) {
            currentNode = currentNode->previous;
        }
    }

    return &currentNode->data;
}

template<typename data_type>
const data_type * CyclicDoubleLinkedList<data_type>::get(std::size_t index) const {
    return const_cast<CyclicDoubleLinkedList *>(this)->get(index);
}

template<typename data_type>
std::size_t CyclicDoubleLinkedList<data_type>::getLength() const {
    return length;
}

template<typename data_type>
bool CyclicDoubleLinkedList<data_type>::isEmpty() const {
    return length == 0;
}

#endif //VTECH_DATA_STRUCTURES_CYCLICDOUBLELINKEDLIST_TPP