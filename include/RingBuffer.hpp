#ifndef RING_BUFFER_H
#define RING_BUFFER_H

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

public:
    /**
     * @brief Create a ring buffer of a given capacity with an initial size of 0.
     *
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
    }

    /**
     * @brief Add an item to the ring buffer.
     *
     * @param value The item to add.
     * @throws std::out_of_range If ring buffer is full.
     */
    void add(T value) {}

    /**
     * @brief Remove and return an item from the ring buffer.
     *
     * @return The removed item.
     * @throws std::out_of_range If the ring buffer is empty.
     */
    T remove()
    {
        return nullptr;
    }

    /**
     * @brief Retrieve the next item to be removed without removing it.
     *
     * @return The next item to be removed.
     */
    T peek() const
    {
        return nullptr;
    }

    /**
     * @brief Check if the ring buffer is currently empty.
     *
     * @return True if the ring buffer is empty, otherwise false.
     */
    bool isEmpty() const
    {
        return false;
    }

    /**
     * @brief Check if the ring buffer is currently full.
     *
     * @return True if the ring buffer is full, otherwise false.
     */
    bool isFull() const
    {
        return false;
    }

    /**
     * @brief Get the current size of the ring buffer.
     *
     * @return The current size.
     */
    int getSize() const
    {
        return 0;
    }

    /**
     * @brief Get the capacity of the ring buffer.
     *
     * @return The capacity.
     */
    int getCapacity() const
    {
        return 0;
    }

    /**
     * @brief Print the contents of the ring buffer.
     */
    void print() const {}
};

#endif
