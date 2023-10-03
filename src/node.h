#ifndef VTECH_DATA_STRUCTURES_NODE_H
#define VTECH_DATA_STRUCTURES_NODE_H

template<typename data_type>
struct Node {
    data_type data;
    Node<data_type> * next;
};

#endif //VTECH_DATA_STRUCTURES_NODE_H
