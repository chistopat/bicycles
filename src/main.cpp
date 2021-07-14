#include <iostream>
#include <memory>

#include "../test/linked_list.h"
#include "mylinkedlist.h"


int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    auto a = obj->get(1); //2
    obj->deleteAtIndex(0);
    auto b = obj->get(0); // 2
    delete obj;

    MyLinkedList list;
    list.addAtIndex(0, 10);
    list.addAtIndex(0, 20);
    list.addAtIndex(1, 30);
    std::cout << list.get(0);
}