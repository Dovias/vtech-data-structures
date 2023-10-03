#ifndef VTECH_DATA_STRUCTURES_DEQUE_H
#define VTECH_DATA_STRUCTURES_DEQUE_H

#include <utility>

template<typename data_type>
class Deque {
public:
    virtual ~Deque() = default;

    virtual bool pushFront(data_type data) = 0;

    virtual bool pushBack(data_type data) = 0;

    virtual bool popFront() = 0;

    virtual bool popBack() = 0;

    virtual void clear() = 0;

    [[nodiscard]] virtual data_type * getFront() = 0;

    [[nodiscard]] virtual const data_type * getFront() const = 0;

    [[nodiscard]] virtual data_type * getBack() = 0;

    [[nodiscard]] virtual const data_type * getBack() const = 0;

    [[nodiscard]] virtual std::size_t getSize() const = 0;

    [[nodiscard]] virtual bool isEmpty() const = 0;
};

template<typename data_type>
void display(Deque<data_type> & deque);

template<typename data_type>
bool reverse(Deque<data_type> & deque);

#include "deque.tpp"

#endif //VTECH_DATA_STRUCTURES_DEQUE_H
