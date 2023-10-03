#ifndef VTECH_DATA_STRUCTURES_STACK_H
#define VTECH_DATA_STRUCTURES_STACK_H

#include <utility>
#include <ostream>

template<typename data_type>
class Stack {
public:
    virtual ~Stack() = default;

    virtual bool push(data_type data) = 0;

    virtual bool pop() = 0;

    virtual void clear() = 0;

    [[nodiscard]] virtual data_type * getTop() = 0;

    [[nodiscard]] virtual const data_type * getTop() const = 0;

    [[nodiscard]] virtual std::size_t getSize() const = 0;

    [[nodiscard]] virtual bool isEmpty() const = 0;
};

template<typename data_type>
void display(Stack<data_type> & stack);

#include "stack.tpp"

#endif //VTECH_DATA_STRUCTURES_STACK_H
