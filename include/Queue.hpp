#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Queue
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
     * @brief Create an empty queue.
     */
    Queue() : size(0), head(nullptr), tail(nullptr) {}

    /**
     * @brief Clean up the stack.
     */
    ~Queue()
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
     * @brief Push a value onto the front of the queue.
     *
     * @param value The value to push.
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
     * @brief Push a value onto the back of the queue.
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
     * @brief Pop a value from the front of the queue.
     *
     * @return The value popped from the queue.
     * @throws std::out_of_range If size of queue is 0.
     */
    T popFront()
    {
        if (head == nullptr && tail == nullptr)
        {
            throw std::out_of_range("No items to pop from queue");
        }
        if (size == 1)
        {
            T value = head->value;
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
            return value;
        }
        Node *node = head;
        head = head->next;
        head->prev = nullptr;
        T value = node->value;
        delete node;
        size--;
        return value;
    }

    /**
     * @brief Pop a value from the back of the queue.
     *
     * @return The value popped from the queue.
     * @throws std::out_of_range If size of queue is 0.
     */
    T popBack()
    {
        if (head == nullptr && tail == nullptr)
        {
            throw std::out_of_range("No items to pop from queue");
        }
        if (size == 1)
        {
            T value = tail->value;
            delete tail;
            head = nullptr;
            tail = nullptr;
            size--;
            return value;
        }
        Node *node = tail;
        tail = tail->prev;
        tail->next = nullptr;
        T value = node->value;
        delete node;
        size--;
        return value;
    }

    /**
     * @brief Peek the value at the front of the queue without popping it.
     *
     * @return The value at the front of the queue.
     */
    T peekFront() const
    {
        if (head == nullptr && tail == nullptr)
        {
            throw std::out_of_range("No items to peek from queue");
        }
        return head->value;
    }

    /**
     * @brief Peek the value at the back of the queue without popping it.
     *
     * @return The value at the back of the queue.
     */
    T peekBack() const
    {
        if (head == nullptr && tail == nullptr)
        {
            throw std::out_of_range("No items to peek from queue");
        }
        return tail->value;
    }

    /**
     * @brief Get the size of the queue.
     *
     * @return The current size.
     */
    int getSize() const
    {
        return size;
    }

    /**
     * @brief Print out the contents of the queue.
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
