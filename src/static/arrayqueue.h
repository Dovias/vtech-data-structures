#ifndef VTECH_DATA_STRUCTURES_ARRAYQUEUE_H
#define VTECH_DATA_STRUCTURES_ARRAYQUEUE_H

#include "../queue.h"
#include <utility>

template<typename data_type>
class ArrayQueue : public Queue<data_type> {
private:
    data_type * front;
    std::size_t capacity;

    std::size_t length;
public:
    explicit ArrayQueue(std::size_t capacity);

    ~ArrayQueue();

    bool enqueue(data_type data);

    bool dequeue();

    void clear();

    [[nodiscard]] data_type * getFront();

    [[nodiscard]] const data_type * getFront() const;

    [[nodiscard]] data_type * getBack();

    [[nodiscard]] const data_type * getBack() const;

    [[nodiscard]] std::size_t getLength() const;

    [[nodiscard]] std::size_t getCapacity() const;

    [[nodiscard]] bool isEmpty() const;

    [[nodiscard]] bool isFull() const;
};

#include "arrayqueue.tpp"

#endif //VTECH_DATA_STRUCTURES_ARRAYQUEUE_H
