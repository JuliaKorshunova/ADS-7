// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <string>

template<typename T>
class TPQueue {
 private:
    struct Item {
        T data;
        Item* next;
        Item* prev;
  };
  Item* head;
  Item* tail;
  TPQueue::Item* create(const T& data) {
        Item* item_name = new Item;
        item_name->data = data;
        item_name->next = nullptr;
        item_name->prev = nullptr;
        return item_name;
  }
 public:
    TPQueue() : head(nullptr), tail(nullptr) { }
    ~TPQueue() {
    void push(const T&);
    T pop();
    void print() const;
  }
struct SYM {
  char ch;
  int prior;
};
template <typename T>
void TPQueue<T>::push(const T& values) {
    if (nullptr == head) {
        head = create(values);
        tail = head;
    } else if (tail->data.prior >= values.prior) {
        if (tail->data.ch == values.ch) {
            tail->data = values;
        } else {
            tail->next = create(values);
            tail->next->prev = tail;
            tail = tail->next;
        }
    } else if (head == tail) {
        tail->prev = create(values);
        head = tail->prev;
        head->next = tail;
    } else {
        Item* tmps = tail;
        while (tmps != head && tmps->data.prior < values.prior) {
            tmps = tmps->pred;
        }
        if (tmps->data.prior > values.prior) {
            Item* ellement = new Item;
            ellement->next = tmps->next;
            ellement->prev = tmps;
            ellement->data = values;
            tmps->next->prev = ellement;
            tmps->next = ellement;
        }
        if (tmps == head && tmps->data.prior < values.prior) {
            head->prev = create(values);
            head = head->prev;
            head->next = tmps;
        }
    }
}
template <typename T>
T TPQueue<T>::pop() {
    if (!head) {
        throw std::string("IS EMPTY!");
    } else {
        Item* temps = head->next;
        T data = head->data;
        delete head;
        head = temps;
        return data;
    }
}
template <typename T>
TPQueue<T>::~TPQueue() {
    while (head) {
        pop();
    }
}
template <typename T>
void TPQueue<T>::print() const {
    Item* temps = head;
    while (temps) {
        std::cout << temps->data << " ";
        temps = temps->next;
    }
    std::cout << std::end;
}
#endif  // INCLUDE_TPQUEUE_H_
