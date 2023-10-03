#ifndef VTECH_DATA_STRUCTURES_STACK_TPP
#define VTECH_DATA_STRUCTURES_STACK_TPP

#include "stack.h"

// Nelabai optimalu, bet tokie reikalavimai kad su tokiomis paciomis stack operacijomis
// turiu isvesti steko elementus.
template<typename data_type>
void display(Stack<data_type> & stack) {
    if (stack.isEmpty()) {
        std::cout << "[]";
        return;
    }
    // Sukuriam buferi, kur laikinai saugosim ispop'intus elementus.
    std::size_t stackBufferSize = stack.getSize();
    auto * stackBuffer = new data_type[stackBufferSize];

    stackBuffer[0] = *stack.getTop();
    std::cout << '[' << stackBuffer[0];

    stack.pop();
    for (std::size_t i = 1; i < stackBufferSize; ++i) {
        stackBuffer[i] = *stack.getTop();
        std::cout << ", " << stackBuffer[i];

        stack.pop();
    }
    std::cout << ']';


    // Kadangi po israsymo stekas prarado elementus, naudojam push ir buferi,
    // kuriuose yra elementai, kad grazintumem elementus atgal.
    for (std::size_t i = stackBufferSize; i --> 0;) {
        stack.push(stackBuffer[i]);
    }

    delete[] stackBuffer;
}

#endif //VTECH_DATA_STRUCTURES_STACK_TPP
