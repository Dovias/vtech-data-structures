#ifndef VTECH_DATA_STRUCTURES_DOUBLELINKEDSTACK_H
#define VTECH_DATA_STRUCTURES_DOUBLELINKEDSTACK_H

#include "../stack.h"
#include "doublelinkedlist.h"

template<typename data_type>
class DoubleLinkedStack : public Stack<data_type> {
private:
    DoubleLinkedList<data_type> list;
public:
    DoubleLinkedStack();

    ~DoubleLinkedStack();

    bool push(data_type data);

    bool pop();

    void clear();

    [[nodiscard]] data_type * getTop();

    [[nodiscard]] const data_type * getTop() const;

    [[nodiscard]] std::size_t getSize() const;

    [[nodiscard]] bool isEmpty() const;
};

#include "doublelinkedstack.tpp"

#endif //VTECH_DATA_STRUCTURES_DOUBLELINKEDSTACK_H
