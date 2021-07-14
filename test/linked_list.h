#pragma once

#include "test_runner.h"
#include "../src/linked_list.h"

namespace bicycles::linked_list {
    void TestConstructors() {
        LinkedList<int> default_constructed;
        ASSERT_EQUAL(default_constructed.ToVector(), std::vector<int>{});

        LinkedList<int> init_listed({1, 2, 3, 4, 5});
        ASSERT_EQUAL(init_listed.ToVector(), std::vector<int>({1, 2, 3, 4, 5}));

        LinkedList<int> init_listed2{1, 2, 3, 4, 5};
        ASSERT_EQUAL(init_listed2.ToVector(), std::vector<int>({1, 2, 3, 4, 5}));

        LinkedList<int> copy_init_listed = {1, 2, 3, 4, 5};
        ASSERT_EQUAL(copy_init_listed.ToVector(), std::vector<int>({1, 2, 3, 4, 5}));
    }

    void TestPushFront() {
        LinkedList<int> linkedList;
        for (const auto& item : std::vector<int>({1, 2, 3, 4, 5})) {
            linkedList.PushFront(item);
        }
        ASSERT_EQUAL(linkedList.ToVector(), std::vector<int>({5, 4, 3, 2, 1}));
    }

    void TestInsertAfter() {
        LinkedList<int> linkedList;
        linkedList.InsertAfter(nullptr, 0);
        std::vector<bicycles::linked_list::Node<int>*> nodes;
        for (const auto& item : std::vector<int>({1, 2, 3, 4, 5})) {
            nodes.push_back(linkedList.PushBack(item));
        }
        linkedList.InsertAfter(nodes[4], 6);
        linkedList.PushBack(7);
        ASSERT_EQUAL(linkedList.ToVector(), std::vector<int>({1, 2, 3, 4, 5, 6, 7}))
    }

    void TestRemoveAfter() {
        LinkedList<int> linkedList;
        linkedList.RemoveAfter(nullptr);
        std::vector<bicycles::linked_list::Node<int>*> nodes;
        for (const auto& item : std::vector<int>({1, 2, 3, 4, 5})) {
            nodes.push_back(linkedList.PushBack(item));
        }
        linkedList.RemoveAfter(nodes[4]);
        linkedList.RemoveAfter(nodes[3]);
        linkedList.RemoveAfter(nodes[1]);
        linkedList.PushBack(0);
        ASSERT_EQUAL(linkedList.ToVector(), std::vector<int>({1, 2, 4, 0}))
    }

    void TestPushBack() {
        LinkedList<int> linkedList;
        for (const auto& item : std::vector<int>({1, 2, 3, 4, 5})) {
            linkedList.PushBack(item);
        }
        ASSERT_EQUAL(linkedList.ToVector(), std::vector<int>({1, 2, 3, 4, 5}));
    }

    void TestPushCross() {
        LinkedList<int> linkedList;
        for (const auto& item : std::vector<int>({1, 2})) {
            linkedList.PushFront(item);
            linkedList.PushBack(item);
        }
        ASSERT_EQUAL(linkedList.ToVector(), std::vector<int>({2, 1, 1, 2}));
    }

    void TestAdvance() {
        LinkedList<int> linkedList({1, 2, 3, 4, 5});
        AssertEqual(LinkedList<int>::Advance(linkedList.Head(), 0)->data, 1);
        AssertEqual(LinkedList<int>::Advance(linkedList.Head(), 4)->data, 5);
        AssertEqual(LinkedList<int>::Advance(linkedList.Head(), 5), nullptr);
        AssertEqual(LinkedList<int>::Advance(linkedList.Head(), 6), nullptr);
        AssertEqual(LinkedList<int>::Advance(linkedList.Head(), -1), nullptr);
    }

    void TestEmpty() {
        LinkedList<int> linkedList;
        ASSERT_EQUAL(linkedList.Empty(), true);
        linkedList.PushBack(1);
        ASSERT_EQUAL(linkedList.Empty(), false);
    }

    void TestPopFront() {
        LinkedList<int> linkedList({1, 2, 3});
        linkedList.PopFront();
        linkedList.PopFront();
        linkedList.PushFront(0);
        ASSERT_EQUAL(linkedList.ToVector(), std::vector<int>({0, 3}));
    }

    void TestAll() {
        TestRunner testRunner;
        RUN_TEST(testRunner, TestConstructors);
        RUN_TEST(testRunner, TestEmpty);
        RUN_TEST(testRunner, TestPushFront);
        RUN_TEST(testRunner, TestPushBack);
        RUN_TEST(testRunner, TestPushCross);
        RUN_TEST(testRunner, TestAdvance);
        RUN_TEST(testRunner, TestInsertAfter);
        RUN_TEST(testRunner, TestRemoveAfter);
        RUN_TEST(testRunner, TestPopFront);
    }
} // namespace bicycles::linked_list