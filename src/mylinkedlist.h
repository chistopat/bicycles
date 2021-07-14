#pragma once

#include "linked_list.h"

using namespace bicycles::linked_list;

class MyLinkedList : LinkedList<int> {
public:
    struct NodeInt : Node<int> {};
    /** Initialize your data structure here. */
    using LinkedList<int>::LinkedList;

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= Size()) {
            return -1;
        }
        return Advance(Head(), index)->data;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be
     * the first node of the linked list. */
    void addAtHead(int val) {
        PushFront(val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        PushBack(val);
    }

    /*
     * Add a node of value val before the index-th node in the linked list.
     * If index equals to the length of linked list, the node will be appended to the end of linked list.
     * If index is greater than the length, the node will not be inserted.
     */
    void addAtIndex(int index, int val) {
        if (index > 0 && index < Size()) {
            InsertAfter(Advance(Head(), index - 1), val);
        } else if (index == 0) {
            PushFront(val);
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index > 0 && index < Size()) {
            RemoveAfter(Advance(Head(), index - 1));
        } else if (index == 0) {
            PopFront();
        }
    }
};