#ifndef VTECH_DATA_STRUCTURES_LIST_TPP
#define VTECH_DATA_STRUCTURES_LIST_TPP

#include "list.h"
#include <iostream>

// Kadangi neparasyta aiskiai kur reikia implementuoti tiesiniu saraso elementu israsyma
// (Ar klaseje ar isoreje), implikuodamas sprendima rasau is isores, nes to prase
// 3 paskiausios strukturos. Sprendimas neoptimalus, kadangi naudoja tik nurodytas operacijas
// sarase. .get() nera geras sprendimas nes jis kas indeksa eina is naujo per masyva
// ieskodamas elemento, o ne nuo praeitos vietos. Sioje vietoje iteratoriai butu geras sprendimas
// sita dalyka is isores isspresti, bet salygos yra salygos. ;)
template<typename data_type>
void display(const List<data_type> & list) {
    if (list.isEmpty()) {
        std::cout << "[]";
        return;
    }
    std::cout << '[' << *list.get(0);

    for (std::size_t i = 1, j = list.getLength(); i < j; ++i) {
        std::cout << ", " << *list.get(i);
    }
    std::cout << ']';
}

#endif //VTECH_DATA_STRUCTURES_LIST_TPP
