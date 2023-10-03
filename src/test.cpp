#include <iostream>

#include "linked/singlylinkedlist.h"
#include "linked/doublelinkedlist.h"
#include "linked/doublelinkedstack.h"
#include "linked/cyclicsinglylinkedlist.h"
#include "linked/cyclicdoublelinkedlist.h"

#include "static/arraystack.h"
#include "static/arrayqueue.h"
#include "static/arraydeque.h"

int main() {
    std::cout << "\n\n\nArrayStack:\n";
    ArrayStack<int> arrayStack(64);
    std::cout << "Capacity: " << arrayStack.getCapacity();
    std::cout << "\nPush:\n";
    arrayStack.push(1);
    arrayStack.push(2);
    arrayStack.push(3);
    arrayStack.push(4);
    arrayStack.push(5);
    display(arrayStack);
    std::cout << "\nSize: " << arrayStack.getSize();
    std::cout << "\nPop:\n";
    arrayStack.pop();
    display(arrayStack);
    std::cout << "\nTop: " << *arrayStack.getTop();
    std::cout << "\nSize: " << arrayStack.getSize();
    std::cout << "\nClear:\n";
    arrayStack.clear();
    display(arrayStack);
    std::cout << "\nSize: " << arrayStack.getSize();
    std::cout << "\nPush:\n";
    arrayStack.push(1);
    display(arrayStack);
    std::cout << "\nSize: " << arrayStack.getSize();



    std::cout << "\n\n\nDoubleLinkedStack:\n";
    DoubleLinkedStack<int> linkedStack;
    std::cout << "Push:\n";
    linkedStack.push(1);
    linkedStack.push(2);
    linkedStack.push(3);
    linkedStack.push(4);
    linkedStack.push(5);
    display(linkedStack);
    std::cout << "\nSize: " << linkedStack.getSize();
    std::cout << "\nPop:\n";
    linkedStack.pop();
    display(linkedStack);
    std::cout << "\nTop: " << *linkedStack.getTop();
    std::cout << "\nSize: " << linkedStack.getSize();
    std::cout << "\nClear:\n";
    linkedStack.clear();
    display(linkedStack);
    std::cout << "\nSize: " << linkedStack.getSize();
    std::cout << "\nPush:\n";
    linkedStack.push(1);
    display(arrayStack);
    std::cout << "\nSize: " << linkedStack.getSize();



    std::cout << "\n\n\nArrayQueue:\n";
    ArrayQueue<int> queue(64);
    std::cout << "Capacity: " << queue.getCapacity() << '\n';
    std::cout << "Enqueue:\n";
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    display(queue);
    std::cout << "\nLength: " << queue.getLength();
    std::cout << "\nReversed:\n";
    reverse(queue);
    display(queue);
    std::cout << "\nDequeue:\n";
    queue.dequeue();
    display(queue);
    std::cout << "\nFront: " << *queue.getFront();
    std::cout << "\nBack: " << *queue.getBack();
    std::cout << "\nSize: " << queue.getLength();
    std::cout << "\nClear:\n";
    queue.clear();
    display(queue);
    std::cout << "\nSize: " << queue.getLength();
    std::cout << "\nEnqueue:\n";
    queue.enqueue(1);
    display(queue);
    std::cout << "\nSize: " << queue.getLength();



    std::cout << "\n\n\nArrayDeque:\n";
    ArrayDeque<int> deque(64);
    std::cout << "Capacity: " << deque.getCapacity() << '\n';
    std::cout << "Push front:\n";
    deque.pushFront(1);
    deque.pushFront(2);
    deque.pushFront(3);
    deque.pushFront(4);
    deque.pushFront(5);
    display(deque);
    std::cout << "\nSize: " << deque.getSize();
    std::cout << "\nReversed:\n";
    reverse(deque);
    display(deque);
    std::cout << "\nPop front:\n";
    deque.popFront();
    display(deque);
    std::cout << "\nPop back:\n";
    deque.popBack();
    display(deque);
    std::cout << "\nFront: " << *deque.getFront();
    std::cout << "\nBack: " << *deque.getBack();
    std::cout << "\nSize: " << deque.getSize();
    std::cout << "\nClear:\n";
    deque.clear();
    display(deque);
    std::cout << "\nSize: " << deque.getSize();
    std::cout << "\nPush back:\n";
    deque.pushBack(1);
    display(deque);
    std::cout << "\nSize: " << deque.getSize();



    std::cout << "\n\n\nSinglyLinkedList:\n";
    SinglyLinkedList<int> singlyList;
    std::cout << "Add first:\n";
    singlyList.addFirst(1);
    singlyList.addFirst(2);
    display(singlyList);
    std::cout << "\nSize: " << singlyList.getLength();
    std::cout << "\nAdd last:\n";
    singlyList.addLast(3);
    singlyList.addLast(4);
    singlyList.addLast(5);
    display(singlyList);
    std::cout << "\nSize: " << singlyList.getLength();
    std::cout << "\nRemove first:\n";
    singlyList.removeFirst();
    display(singlyList);
    std::cout << "\nSize: " << singlyList.getLength();
    std::cout << "\nRemove last:\n";
    singlyList.removeLast();
    display(singlyList);
    std::cout << "\nSize: " << singlyList.getLength();
    std::cout << "\nRemove middle:\n";
    singlyList.removeMiddle();
    display(singlyList);
    std::cout << "\nSize: " << singlyList.getLength();
    std::cout << "\nReversed:\n";
    singlyList.reverse();
    display(singlyList);
    std::cout << "\nFirst: " << *singlyList.getFirst();
    std::cout << "\nLast: " << *singlyList.getLast();
    std::cout << "\nMiddle: " << *singlyList.getMiddle();
    std::cout << "\nClear:\n";
    singlyList.clear();
    display(singlyList);
    std::cout << "\nSize: " << singlyList.getLength();
    std::cout << "\nAdd last:\n";
    singlyList.addLast(1);
    display(singlyList);
    std::cout << "\nSize: " << singlyList.getLength();



    std::cout << "\n\n\nDoubleLinkedList:\n";
    DoubleLinkedList<int> doubleList;
    std::cout << "Add first:\n";
    doubleList.addFirst(1);
    doubleList.addFirst(2);
    display(doubleList);
    std::cout << "\nSize: " << doubleList.getLength();
    std::cout << "\nAdd last:\n";
    doubleList.addLast(4);
    doubleList.addLast(5);
    display(doubleList);
    std::cout << "\nSize: " << doubleList.getLength();
    std::cout << "\nAdd middle:\n";
    doubleList.addMiddle(3);
    display(doubleList);
    std::cout << "\nSize: " << doubleList.getLength();
    std::cout << "\nRemove first:\n";
    doubleList.removeFirst();
    display(doubleList);
    std::cout << "\nSize: " << doubleList.getLength();
    std::cout << "\nRemove last:\n";
    doubleList.removeLast();
    display(doubleList);
    std::cout << "\nSize: " << doubleList.getLength();
    std::cout << "\nRemove middle:\n";
    doubleList.removeMiddle();
    display(doubleList);
    std::cout << "\nSize: " << doubleList.getLength();
    std::cout << "\nReversed:\n";
    doubleList.reverse();
    display(doubleList);
    std::cout << "\nFirst: " << *doubleList.getFirst();
    std::cout << "\nLast: " << *doubleList.getLast();
    std::cout << "\nMiddle: " << *doubleList.getMiddle();
    std::cout << "\nClear:\n";
    doubleList.clear();
    display(doubleList);
    std::cout << "\nSize: " << doubleList.getLength();
    std::cout << "\nAdd last:\n";
    doubleList.addLast(1);
    display(doubleList);
    std::cout << "\nSize: " << doubleList.getLength();



    std::cout << "\n\n\nCyclicSinglyLinkedList:\n";
    CyclicSinglyLinkedList<int> cyclicSinglyList;
    std::cout << "Add first:\n";
    cyclicSinglyList.addFirst(1);
    cyclicSinglyList.addFirst(2);
    display(cyclicSinglyList);
    std::cout << "\nSize: " << cyclicSinglyList.getLength();
    std::cout << "\nAdd last:\n";
    cyclicSinglyList.addLast(4);
    cyclicSinglyList.addLast(5);
    display(cyclicSinglyList);
    std::cout << "\nSize: " << cyclicSinglyList.getLength();
    std::cout << "\nAdd middle:\n";
    cyclicSinglyList.addMiddle(3);
    display(cyclicSinglyList);
    std::cout << "\nSize: " << cyclicSinglyList.getLength();
    std::cout << "\nRemove first:\n";
    cyclicSinglyList.removeFirst();
    display(cyclicSinglyList);
    std::cout << "\nSize: " << cyclicSinglyList.getLength();
    std::cout << "\nRemove last:\n";
    cyclicSinglyList.removeLast();
    display(cyclicSinglyList);
    std::cout << "\nSize: " << cyclicSinglyList.getLength();
    std::cout << "\nRemove middle:\n";
    cyclicSinglyList.removeMiddle();
    display(cyclicSinglyList);
    std::cout << "\nSize: " << cyclicSinglyList.getLength();
    std::cout << "\nReversed:\n";
    cyclicSinglyList.reverse();
    display(cyclicSinglyList);
    std::cout << "\nFirst: " << *cyclicSinglyList.getFirst();
    std::cout << "\nLast: " << *cyclicSinglyList.getLast();
    std::cout << "\nMiddle: " << *cyclicSinglyList.getMiddle();
    std::cout << "\nClear:\n";
    cyclicSinglyList.clear();
    display(cyclicSinglyList);
    std::cout << "\nSize: " << cyclicSinglyList.getLength();
    std::cout << "\nAdd last:\n";
    cyclicSinglyList.addLast(1);
    display(cyclicSinglyList);
    std::cout << "\nSize: " << cyclicSinglyList.getLength();



    std::cout << "\n\n\nCyclicDoubleLinkedList:\n";
    CyclicDoubleLinkedList<int> cyclicDoubleList;
    std::cout << "Add first:\n";
    cyclicDoubleList.addFirst(1);
    cyclicDoubleList.addFirst(2);
    display(cyclicDoubleList);
    std::cout << "\nSize: " << cyclicDoubleList.getLength();
    std::cout << "\nAdd last:\n";
    cyclicDoubleList.addLast(4);
    cyclicDoubleList.addLast(5);
    display(cyclicDoubleList);
    std::cout << "\nSize: " << cyclicDoubleList.getLength();
    std::cout << "\nAdd middle:\n";
    cyclicDoubleList.addMiddle(3);
    display(cyclicDoubleList);
    std::cout << "\nSize: " << cyclicDoubleList.getLength();
    std::cout << "\nRemove first:\n";
    cyclicDoubleList.removeFirst();
    display(cyclicDoubleList);
    std::cout << "\nSize: " << cyclicDoubleList.getLength();
    std::cout << "\nRemove last:\n";
    cyclicDoubleList.removeLast();
    display(cyclicDoubleList);
    std::cout << "\nSize: " << cyclicDoubleList.getLength();
    std::cout << "\nRemove middle:\n";
    cyclicDoubleList.removeMiddle();
    display(cyclicDoubleList);
    std::cout << "\nSize: " << cyclicDoubleList.getLength();
    std::cout << "\nReversed:\n";
    cyclicDoubleList.reverse();
    display(cyclicDoubleList);
    std::cout << "\nFirst: " << *cyclicDoubleList.getFirst();
    std::cout << "\nLast: " << *cyclicDoubleList.getLast();
    std::cout << "\nMiddle: " << *cyclicDoubleList.getMiddle();
    std::cout << "\nClear:\n";
    cyclicDoubleList.clear();
    display(cyclicDoubleList);
    std::cout << "\nSize: " << cyclicDoubleList.getLength();
    std::cout << "\nAdd last:\n";
    cyclicDoubleList.addLast(1);
    display(cyclicDoubleList);
    std::cout << "\nSize: " << cyclicDoubleList.getLength();
    return 0;
}