#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <initializer_list>

namespace bicycles::linked_list {

    template <typename Type>
    struct Node {
        Type data;
        Node* next;

        Node() : data({}), next(nullptr) {}
        explicit Node(Type value) : data(value), next(nullptr) {}
        Node(Type value, Node* next) : data(value), next(next) {}
    };

    template <typename Type>
    class LinkedList {
    private:
        Node<Type>* head_;
        Node<Type>* tail_;
        size_t size_;

    public:
        LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}
        LinkedList(std::initializer_list<Type> initializerList) : size_(0) {
            for (const auto& item : initializerList) {
                PushBack(item);
                ++size_;
            }
        }
        const Node<Type>* Head() const { return head_; }
        Node<Type>* Head() { return head_; }
        bool Empty() const { return size_ == 0; }
        size_t Size() const { return size_; }
        Node<Type>* PushBack(Type value) {
            if (Empty()) {
                head_ = new Node<int>(value);
                tail_ = head_;
            } else {
                tail_->next = new Node<int>(value);
                tail_ = tail_->next;
            }
            ++size_;
            return tail_;
        }

        Node<Type>* PushFront(Type value) {
            if (Empty()) return PushBack(value);
            head_ = new Node<Type>(value, head_);
            ++size_;
            return head_;
        }

        void PopFront() {
            if (!Empty()) {
                auto temp = head_;
                if (tail_ == head_) {
                    tail_ = head_->next;
                }
                head_ = head_->next;
                delete temp;
                --size_;
            }
        }

        static Node<Type>* Advance(Node<Type>* begin, size_t n) {
            auto result = begin;
            for (size_t i = 0; i<=n && result; ++i) {
                if (i==n) return result;
                result = result->next;
            }
            return result;
        }

        Node<Type>* InsertAfter(Node<Type>* node, Type value) {
            if (node) {
                if (node == tail_) return PushBack(value);
                node->next = new Node(value, node->next);
                ++size_;
                return node->next;
            }
            return node;
        }

        void RemoveAfter(Node<Type>* node) {
            if(node && node->next) {
                auto current = node->next;
                if (current == tail_) tail_=node;
                node->next = current->next;
                delete current;
                --size_;
            }
        }



    public:

        std::vector<Type> ToVector() const {
            std::vector<Type> result;
            auto node = head_;
            while (node) {
                result.push_back(node->data);
                node = node->next;
            }
            return result;
        }

    };
} // namespace bicycles::LinkedList;
