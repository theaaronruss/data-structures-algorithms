#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T value;
        Node *next;
        Node *prev;
    };
    int size;
    Node *head;
    Node *tail;
    Node *traverse(int index)
    {
        Node *currNode = head;
        for (int i = 0; i < index && currNode != nullptr; i++)
        {
            currNode = currNode->next;
        }
        return currNode;
    }

public:
    /**
     * @brief Create empty linked list.
     */
    LinkedList() : size(0), head(nullptr), tail(nullptr) {}

    /**
     * @brief Clean up linked list.
     */
    ~LinkedList()
    {
        Node *currNode = head;
        while (currNode != nullptr)
        {
            Node *nextNode = currNode->next;
            delete currNode;
            currNode = nextNode;
        }
    }

    /**
     * @brief Push a value to the front of the list.
     */
    void pushFront(T value)
    {
        Node *node = new Node{value, head, nullptr};
        if (head == nullptr && tail == nullptr)
        {
            head = tail = node;
            size++;
            return;
        }
        head->prev = node;
        head = node;
        size++;
    }

    /**
     * @brief Push a value to the back of the list.
     */
    void pushBack(T value)
    {
        Node *node = new Node{value, nullptr, tail};
        if (head == nullptr && tail == nullptr)
        {
            head = tail = node;
            size++;
            return;
        }
        tail->next = node;
        tail = node;
        size++;
    }

    /**
     * @brief Insert a value into the list at a given index. If the given index is equal to the current size, the item
     * is appended to the list.
     *
     * @param index The index to insert the item at.
     * @param value The value to insert.
     * @throws std::out_of_range If index is out of bounds.
     */
    void insert(int index, T value)
    {
        if (index < 0 || index > size)
        {
            throw std::out_of_range("Invalid index");
        }
        if (index == size)
        {
            pushBack(value);
            return;
        }
        if (index == 0)
        {
            pushFront(value);
            return;
        }
        Node *currNode = head;
        for (int i = 0; i < index; i++)
        {
            currNode = currNode->next;
        }
        Node *newNode = new Node{value, currNode, currNode->prev};
        currNode->prev->next = newNode;
        currNode->prev = newNode;
        size++;
    }

    /**
     * @brief Remove an item at the given index.
     *
     * @param index The index to remove the item at.
     * @return The removed item.
     * @throws std::out_of_range If index is out of bounds.
     */
    T remove(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Invalid index");
        }
        Node *currNode = traverse(index);
        if (currNode->prev != nullptr)
        {
            currNode->prev->next = currNode->next;
        }
        else
        {
            head = currNode->next;
        }
        if (currNode->next != nullptr)
        {
            currNode->next->prev = currNode->prev;
        }
        else
        {
            tail = currNode->prev;
        }
        T value = currNode->value;
        delete currNode;
        size--;
        return value;
    }

    /**
     * @brief Get the value at a given index.
     *
     * @param index The index of the item to retrieve.
     * @return The retrieved item.
     */
    T get(int index) const
    {
        return nullptr;
    }

    /**
     * @brief Get the size of the list.
     *
     * @return The current size.
     */
    int getSize() const
    {
        return size;
    }

    /**
     * @brief Print out the contents of the list.
     */
    void print() const
    {
        std::cout << "[ ";
        Node *currNode = head;
        while (currNode != nullptr)
        {
            std::cout << currNode->value << " ";
            currNode = currNode->next;
        }
        std::cout << "]\n";
    }
};

#endif
