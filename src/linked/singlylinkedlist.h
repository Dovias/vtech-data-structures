#ifndef VTECH_DATA_STRUCTURES_SINGLYLINKEDLIST_H
#define VTECH_DATA_STRUCTURES_SINGLYLINKEDLIST_H

#include "../list.h"
#include "../node.h"

#include <utility>

template<typename data_type>
class SinglyLinkedList : public List<data_type> {
private:
    Node<data_type> * head;
    Node<data_type> * tail;

    std::size_t length;
public:
    SinglyLinkedList();

    ~SinglyLinkedList();


    bool addFirst(data_type data);

    bool addLast(data_type data);

    bool addMiddle(data_type data);

    bool add(data_type data, std::size_t index);

    bool removeFirst();

    bool removeLast();

    bool removeMiddle();

    bool remove(std::size_t index);

    void clear();

    bool reverse();

    [[nodiscard]] data_type * getFirst();

    [[nodiscard]] const data_type * getFirst() const;

    [[nodiscard]] data_type * getLast();

    [[nodiscard]] const data_type * getLast() const;

    [[nodiscard]] data_type * getMiddle();

    [[nodiscard]] const data_type * getMiddle() const;

    [[nodiscard]] data_type * get(std::size_t index);

    [[nodiscard]] const data_type * get(std::size_t index) const;

    [[nodiscard]] std::size_t getLength() const;

    [[nodiscard]] bool isEmpty() const;
};

#include "singlylinkedlist.tpp"

#endif // VTECH_DATA_STRUCTURES_SINGLYLINKEDLIST_H
