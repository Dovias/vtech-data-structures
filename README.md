# vtech-data-structures
vtech-data-structures is a project for my studies at VILNIUS TECH university. This project involves implementing 8 different types of algorithms for these data structures:
- Array stack
- Double linked stack
- Array deque
- Array queue
- Singly linked list
- Cycled singly linked list
- Double linked list
- Cycled double linked list

## Note 📝
Not everything is implemented in the best way possible. Mainly missing are the iterator support, which could be implemented to properly fix the display functions to represent
the data structures view in the string format (they do work, but quite inefficiently), but due to constrainst that I was given, I could not do this. Also take attention in the
consistency of some architecture of the data structures. Some structures hold the reversing for the data implementation outside the class scope, while some implement it externally
(this is normal and it was done intentionally for constrain reasons).

## Building ⚒️
Since this is a basic project that I have done, I have provided a simple CMake support to build the application properly. First copy the files by having ``git`` installed on
a computer and run this simple command to clone the repository: ``git clone https://github.com/Dovias/vtech-data-structures.git``. After it is done, install ``cmake`` 
and type  ``cmake .`` and ``cmake --build`` inside the git repository directory to build this project.
