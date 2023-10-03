#ifndef VTECH_DATA_STRUCTURES_DEQUE_TPP
#define VTECH_DATA_STRUCTURES_DEQUE_TPP

#include "deque.h"
#include <iostream>

// Nelabai optimalu, bet tokie reikalavimai kad su tokiomis paciomis queue operacijomis
// turiu isvesti elementus.
template<typename data_type>
void display(Deque<data_type> & deque) {
    if (deque.isEmpty()) {
        std::cout << "[]";
        return;
    }
    // Sukuriam buferi, kur laikinai saugosim pop'intus elementus.
    std::size_t dequeBufferSize = deque.getSize();
    auto * dequeBuffer = new data_type[dequeBufferSize];

    dequeBuffer[0] = *deque.getFront();
    std::cout << '[' << dequeBuffer[0];

    deque.popFront();
    for (std::size_t i = 1; i < dequeBufferSize; ++i) {
        dequeBuffer[i] = *deque.getFront();
        std::cout << ", " << dequeBuffer[i];

        deque.popFront();
    }
    std::cout << ']';

    // Kadangi po israsymo dekas prarado elementus, naudojam pushFront ir buferi,
    // kuriame yra elementai, kad grazintumem elementus atgal.
    for (std::size_t i = 0; i < dequeBufferSize; ++i) {
        deque.pushBack(dequeBuffer[i]);
    }

    delete[] dequeBuffer;
}

template<typename data_type>
bool reverse(Deque<data_type> & deque) {
    if (deque.getSize() <= 1) {
        return false;
    }

    // Sukuriam buferi, kur laikinai saugosim pop'intus elementus.
    std::size_t dequeBufferSize = deque.getSize();
    auto * dequeBuffer = new data_type[dequeBufferSize];

    for (std::size_t i = 0; i < dequeBufferSize; ++i) {
        dequeBuffer[i] = *deque.getBack();
        deque.popBack();
    }

    // Kadangi po nuskaitymo i buferi dekas prarado elementus, naudojam pushBack ir buferi,
    // kuriame yra elementai, kad apverstumem elementu eiliskuma.
    for (std::size_t i = 0; i < dequeBufferSize; ++i) {
        deque.pushBack(dequeBuffer[i]);
    }

    delete[] dequeBuffer;
    return true;
}

#endif //VTECH_DATA_STRUCTURES_DEQUE_TPP
