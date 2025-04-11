#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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
    void pushFront(T value) {}

    /**
     * @brief Push a value to the back of the list.
     */
    void pushBack(T value) {}

    /**
     * @brief Insert a value into the list at a given index.
     *
     * @param index The index to insert the item at.
     * @param value The value to insert.
     * @throws std::out_of_range If index is out of bounds.
     */
    void insert(int index, T value) {}

    /**
     * @brief Remove an item at the given index.
     *
     * @param index The index to remove the item at.
     * @return The removed item.
     */
    T remove(int index) {}

    /**
     * @brief Get the value at a given index.
     *
     * @param index The index of the item to retrieve.
     * @return The retrieved item.
     */
    T get(int index) const {}

    /**
     * @brief Get the size of the list.
     *
     * @return The current size.
     */
    int getSize() const {}
};

#endif
