#ifndef VTECH_DATA_STRUCTURES_CYCLICDOUBLELINKEDLIST_H
#define VTECH_DATA_STRUCTURES_CYCLICDOUBLELINKEDLIST_H

#include "../list.h"
#include "../bidirectionalnode.h"

#include <utility>

template<typename data_type>
class CyclicDoubleLinkedList : public List<data_type> {
private:
    BidirectionalNode<data_type> * last;

    std::size_t length;
public:
    CyclicDoubleLinkedList();

    ~CyclicDoubleLinkedList();

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

#include "cyclicdoublelinkedlist.tpp"

#endif //VTECH_DATA_STRUCTURES_CYCLICDOUBLELINKEDLIST_H
