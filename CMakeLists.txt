cmake_minimum_required(VERSION 3.25)
project(vtech_data_structures)

set(CMAKE_CXX_STANDARD 17)

add_executable(vtech_data_structures
        # Test application source code
        src/test.cpp

        # Data structure source code
        src/stack.h
        src/stack.tpp
        src/static/arraystack.h
        src/static/arraystack.tpp
        src/linked/doublelinkedstack.h
        src/linked/doublelinkedstack.tpp

        src/queue.h
        src/queue.tpp
        src/static/arrayqueue.tpp
        src/static/arrayqueue.h

        src/list.h
        src/list.tpp
        src/node.h
        src/linked/singlylinkedlist.h
        src/linked/singlylinkedlist.tpp
        src/bidirectionalnode.h
        src/linked/doublelinkedlist.h
        src/linked/doublelinkedlist.tpp
        src/linked/cyclicsinglylinkedlist.h
        src/linked/cyclicsinglylinkedlist.tpp
        src/linked/cyclicdoublelinkedlist.h
        src/linked/cyclicdoublelinkedlist.tpp

        src/deque.h
        src/deque.tpp
        src/static/arraydeque.h
        src/static/arraydeque.tpp
)
