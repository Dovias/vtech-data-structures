#ifndef VTECH_DATA_STRUCTURES_QUEUE_TPP
#define VTECH_DATA_STRUCTURES_QUEUE_TPP

#include "queue.h"
#include "static/arraystack.h"

#include <iostream>

// Nelabai optimalu, bet tokie reikalavimai kad su tokiomis paciomis queue operacijomis
// turiu isvesti elementus.
template<typename data_type>
void display(Queue<data_type> & queue) {
    if (queue.isEmpty()) {
        std::cout << "[]";
        return;
    }
    // Sukuriam buferi, kur laikinai saugosim dequeue'intus elementus.
    std::size_t queueBufferSize = queue.getLength();
    auto * queueBuffer = new data_type[queueBufferSize];

    queueBuffer[0] = *queue.getFront();
    std::cout << '[' << queueBuffer[0];

    queue.dequeue();
    for (std::size_t i = 1; i < queueBufferSize; ++i) {
        queueBuffer[i] = *queue.getFront();
        std::cout << ", " << queueBuffer[i];

        queue.dequeue();
    }
    std::cout << ']';

    // Kadangi po israsymo eile prarado elementus, naudojam enqueue ir buferi,
    // kuriame yra elementai, kad grazintumem elementus atgal.
    for (std::size_t i = 0; i < queueBufferSize; ++i) {
        queue.enqueue(queueBuffer[i]);
    }

    delete[] queueBuffer;
}

template<typename data_type>
bool reverse(Queue<data_type> & queue) {
    if (queue.getLength() <= 1) {
        return false;
    }

    ArrayStack<data_type> bufferStack(queue.getLength());

    data_type * data;
    while ((data = queue.getFront()) != nullptr) {
        bufferStack.push(*data);

        queue.dequeue();
    }
    while ((data = bufferStack.getTop()) != nullptr) {
        queue.enqueue(*data);

        bufferStack.pop();
    }
    return true;
}


#endif //VTECH_DATA_STRUCTURES_QUEUE_TPP
