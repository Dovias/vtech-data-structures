#ifndef VTECH_DATA_STRUCTURES_BIDIRECTIONALNODE_H
#define VTECH_DATA_STRUCTURES_BIDIRECTIONALNODE_H

template<typename data_type>
struct BidirectionalNode {
    data_type data;
    BidirectionalNode<data_type> * previous;
    BidirectionalNode<data_type> * next;
};

#endif //VTECH_DATA_STRUCTURES_BIDIRECTIONALNODE_H
