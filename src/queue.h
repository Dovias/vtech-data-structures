#ifndef VTECH_DATA_STRUCTURES_QUEUE_H
#define VTECH_DATA_STRUCTURES_QUEUE_H

#include <utility>

template<typename data_type>
class Queue {
public:
    virtual ~Queue() = default;

    virtual bool enqueue(data_type data) = 0;

    virtual bool dequeue() = 0;

    virtual void clear() = 0;

    [[nodiscard]] virtual data_type * getFront() = 0;

    [[nodiscard]] virtual const data_type * getFront() const = 0;

    [[nodiscard]] virtual data_type * getBack() = 0;

    [[nodiscard]] virtual const data_type * getBack() const = 0;

    [[nodiscard]] virtual std::size_t getLength() const = 0;

    [[nodiscard]] virtual bool isEmpty() const = 0;
};

template<typename data_type>
void display(Queue<data_type> & queue);

template<typename data_type>
bool reverse(Queue<data_type> & queue);

#include "queue.tpp"

#endif //VTECH_DATA_STRUCTURES_QUEUE_H
