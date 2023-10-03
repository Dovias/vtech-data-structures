#ifndef VTECH_DATA_STRUCTURES_ARRAYDEQUE_H
#define VTECH_DATA_STRUCTURES_ARRAYDEQUE_H

#include "../deque.h"

template<typename data_type>
class ArrayDeque : public Deque<data_type> {
private:
    std::size_t capacity;
    data_type * front;

    std::size_t size;
public:
    explicit ArrayDeque(std::size_t capacity);

    ~ArrayDeque();

    bool pushFront(data_type data);

    bool pushBack(data_type data);

    bool popFront();

    bool popBack();

    void clear();

    [[nodiscard]] data_type * getFront();

    [[nodiscard]] const data_type * getFront() const;

    [[nodiscard]] data_type * getBack();

    [[nodiscard]] const data_type * getBack() const;

    [[nodiscard]] std::size_t getSize() const;

    [[nodiscard]] std::size_t getCapacity() const;

    [[nodiscard]] bool isEmpty() const;

    [[nodiscard]] bool isFull() const;
};

#include "arraydeque.tpp"

#endif //VTECH_DATA_STRUCTURES_ARRAYDEQUE_H
