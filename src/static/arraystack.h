#ifndef VTECH_DATA_STRUCTURES_ARRAYSTACK_H
#define VTECH_DATA_STRUCTURES_ARRAYSTACK_H

#include <utility>
#include "../stack.h"

template<typename data_type>
class ArrayStack : public Stack<data_type> {
private:
    std::size_t capacity;
    data_type * top;

    std::size_t size;
public:
    explicit ArrayStack(std::size_t capacity);

    ~ArrayStack();

    bool push(data_type data);

    bool pop();

    void clear();

    [[nodiscard]] data_type * getTop();

    [[nodiscard]] const data_type * getTop() const;

    [[nodiscard]] std::size_t getSize() const;

    [[nodiscard]] std::size_t getCapacity() const;

    [[nodiscard]] bool isEmpty() const;

    [[nodiscard]] bool isFull() const;
};

#include "arraystack.tpp"

#endif //VTECH_DATA_STRUCTURES_ARRAYSTACK_H
