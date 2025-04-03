#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>

struct Node
{
    int value;
    Node *next = nullptr;
};

class LinkedList
{
public:
    LinkedList() : length{0}, head{nullptr}, tail{nullptr} {}
    ~LinkedList();
    void append(int value);
    void prepend(int value);
    void insert(int index, int value);
    void remove(int index);
    int get(int index);
    void print();

private:
    size_t length;
    Node *head;
    Node *tail;
};

#endif
