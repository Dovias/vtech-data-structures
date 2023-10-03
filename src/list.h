#ifndef VTECH_DATA_STRUCTURES_LIST_H
#define VTECH_DATA_STRUCTURES_LIST_H

#include <utility>

template<typename data_type>
class List {
public:
    virtual ~List() = default;

    virtual bool addFirst(data_type data) = 0;

    virtual bool addLast(data_type data) = 0;

    virtual bool addMiddle(data_type data) = 0;

    virtual bool add(data_type data, std::size_t index) = 0;

    virtual bool removeFirst() = 0;

    virtual bool removeLast() = 0;

    virtual bool removeMiddle() = 0;

    virtual bool remove(std::size_t index) = 0;

    virtual void clear() = 0;

    virtual bool reverse() = 0;

    [[nodiscard]] virtual data_type * getFirst() = 0;

    [[nodiscard]] virtual const data_type * getFirst() const = 0;

    [[nodiscard]] virtual data_type * getLast() = 0;

    [[nodiscard]] virtual const data_type * getLast() const = 0;

    [[nodiscard]] virtual data_type * getMiddle() = 0;

    [[nodiscard]] virtual const data_type * getMiddle() const = 0;

    [[nodiscard]] virtual data_type * get(std::size_t index) = 0;

    [[nodiscard]] virtual const data_type * get(std::size_t index) const = 0;

    [[nodiscard]] virtual std::size_t getLength() const = 0;

    [[nodiscard]] virtual bool isEmpty() const = 0;
};

template<typename data_type>
void display(const List<data_type> & list);

#include "list.tpp"

#endif //VTECH_DATA_STRUCTURES_LIST_H
