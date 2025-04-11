#ifndef STACK_H
#define STACK_H

#include <iostream>

template <typename T>
class Stack
{
private:
    struct Node
    {
        T value;
        Node *next;
    };
    int size;
    Node *head;

public:
    /**
     * @brief Initialize empty stack.
     */
    Stack() : size(0), head(nullptr) {}

    /**
     * @brief Clean up the stack.
     */
    ~Stack()
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
     * @brief Push an item onto the stack.
     *
     * @param item The item to push.
     */
    void push(T item)
    {
        Node *node = new Node{item, head};
        head = node;
        size++;
    }

    /**
     * @brief Pop the value off the top of the stack.
     *
     * @return The value from the top of the stack.
     * @throws std::out_of_range If the stack size is zero.
     */
    T pop()
    {
        if (size == 0)
        {
            throw std::out_of_range("Nothing in stack to pop");
        }
        Node *node = head;
        head = head->next;
        T value = node->value;
        delete node;
        size--;
        return value;
    }

    /**
     * @brief Peek the value at the top of the stack.
     *
     * @return The next value to be popped from the stack.
     */
    const T peek() const
    {
        if (size == 0)
        {
            throw std::out_of_range("Nothing in stack to peek");
        }
        return head->value;
    }

    /**
     * @brief Check if the stack is currently empty.
     *
     * @return True if the stack is empty, otherwise false.
     */
    bool isEmpty() const
    {
        return size == 0;
    }

    /**
     * @brief Get the size of the stack.
     *
     * @return The current size.
     */
    int getSize() const
    {
        return size;
    }

    /**
     * @brief Print out the contents of the stack.
     */
    void print() const
    {
        Node *currNode = head;
        while (currNode != nullptr)
        {
            std::cout << "[ " << currNode->value << " ]\n";
            currNode = currNode->next;
        }
    }
};

#endif
