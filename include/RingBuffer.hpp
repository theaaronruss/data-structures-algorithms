#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <iostream>
#include <stdexcept>

template <typename T>
class RingBuffer
{
private:
    int capacity;
    int size;
    int headIndex;
    int tailIndex;
    T *data;
    int getArrayIndex(int index) const
    {
        return (capacity + (index % capacity)) % capacity;
    }

public:
    /**
     * @brief Create a ring buffer of a given capacity with an initial size of 0.
     *
     * @param capacity The initial capacity of the ring buffer.
     * @throws std::invalid_argument If capacity is not at least 1.
     */
    RingBuffer(int capacity) : capacity(capacity), size(0), headIndex(0), tailIndex(0), data(new T[capacity])
    {
        if (capacity < 1)
        {
            throw std::invalid_argument("Capacity must be at least 1");
        }
    }

    /**
     * @brief Clean up the ring buffer.
     */
    ~RingBuffer()
    {
        delete[] data;
        data = nullptr;
    }

    /**
     * @brief Add an item to the front of the ring buffer.
     *
     * @param value The item to add.
     * @throw std::out_of_range If ring buffer is full.
     */
    void pushFront(T value)
    {
        if (size >= capacity)
        {
            throw std::out_of_range("Ring buffer is full");
        }
        headIndex--;
        int index = getArrayIndex(headIndex);
        data[index] = value;
        size++;
    }

    /**
     * @brief Add an item to the back of the ring buffer.
     *
     * @param value The item to add.
     * @throw std::out_of_range If ring buffer is full.
     */
    void pushBack(T value)
    {
        if (size >= capacity)
        {
            throw std::out_of_range("Ring buffer is full");
        }
        int index = getArrayIndex(tailIndex);
        data[index] = value;
        tailIndex++;
        size++;
    }

    /**
     * @brief Remove and return an item from the front of the ring buffer.
     *
     * @return The removed item.
     * @throws std::out_of_range If the ring buffer is empty.
     */
    T popFront()
    {
        if (size == 0)
        {
            throw std::out_of_range("Ring buffer is empty");
        }
        int index = getArrayIndex(headIndex);
        T value = data[index];
        headIndex++;
        size--;
        return value;
    }

    /**
     * @brief Remove and return an item from the back of the ring buffer.
     *
     * @return the removed item.
     * @throws std::out_of_range If the ring buffer is empty.
     */
    T popBack()
    {
        if (size == 0)
        {
            throw std::out_of_range("Ring buffer is empty");
        }
        int index = getArrayIndex(tailIndex);
        T value = data[index];
        tailIndex--;
        size--;
        return value;
    }

    /**
     * @brief Retrieve the next item to be removed from the front of the ring buffer without removing it.
     *
     * @return The next item to be removed.
     * @throws std::out_of_range If ring buffer is empty.
     */
    T peekFront() const
    {
        if (size == 0)
        {
            throw std::out_of_range("Ring buffer is empty");
        }
        int index = getArrayIndex(headIndex);
        return data[index];
    }

    /**
     * @brief Retrieve the next item to be removed from the back of the ring buffer without removing it.
     *
     * @return The next item to be removed.
     * @throws std::out_of_range If ring buffer is empty.
     */
    T peekBack() const
    {
        if (size == 0)
        {
            throw std::out_of_range("Ring buffer is empty");
        }
        int index = getArrayIndex(tailIndex);
        return data[index];
    }

    /**
     * @brief Check if the ring buffer is currently empty.
     *
     * @return True if the ring buffer is empty, otherwise false.
     */
    bool isEmpty() const
    {
        return size == 0;
    }

    /**
     * @brief Check if the ring buffer is currently full.
     *
     * @return True if the ring buffer is full, otherwise false.
     */
    bool isFull() const
    {
        return size == capacity;
    }

    /**
     * @brief Get the current size of the ring buffer.
     *
     * @return The current size.
     */
    int getSize() const
    {
        return size;
    }

    /**
     * @brief Get the capacity of the ring buffer.
     *
     * @return The capacity.
     */
    int getCapacity() const
    {
        return capacity;
    }

    /**
     * @brief Print the contents of the ring buffer.
     */
    void print() const
    {
        std::cout << "[ ";
        for (int i = 0; i < size; i++)
        {
            int index = getArrayIndex(headIndex + i);
            std::cout << data[index] << " ";
        }
        std::cout << "]\n";
    }
};

#endif
